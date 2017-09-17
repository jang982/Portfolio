#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import division
from __future__ import print_function
from vizdoom import *
import itertools as it
import pickle
from random import sample, randint, random
from time import time, sleep
import numpy as np
import skimage.color, skimage.transform
import tensorflow as tf
from tqdm import trange

# 러닝레이트를 세팅합니다
learning_rate = 0.0025
discount_factor = 0.99

#epoch를 0으로하면 바로 화면을 볼 수 있습니다.
epochs = 0
learning_steps_per_epoch = 2000

#메모리 사이즈를 정합니다
replay_memory_size = 10000

# 배치사이즈 부분입니다
batch_size = 64

# 테스트할때 에피소드를 정합니다
test_episodes_per_epoch = 100


frame_repeat = 12
resolution = (30, 45)
episodes_to_watch = 10


#세이브 로드설정
save_model = False
load_model = True
skip_learning = False

# config파일과 세이브로드파일경로를 설정합니다.


model_savefile = "../../tmp/simpler3.ckpt"
config_file_path = "../../scenarios/simpler_basic.cfg"


# 비즈둠의 환경을 설정합니다. config파일을 넣으면 액션과 환경을 자동으로 설정해줍니다.
def initialize_vizdoom(config_file_path):
    print("Initializing doom...")
    game = DoomGame()
    game.load_config(config_file_path)
    game.set_window_visible(True)
    game.set_mode(Mode.PLAYER)
    game.set_screen_format(ScreenFormat.GRAY8)
    game.set_screen_resolution(ScreenResolution.RES_640X480)
    game.init()
    print("Doom initialized.")
    return game


# Converts and down-samples the input image
def preprocess(img):
    img = skimage.transform.resize(img,resolution,mode='constant')
    img = img.astype(np.float32)
    return img

#메모리 저장용 함수

class ReplayMemory:
    def __init__(self, capacity):
        channels = 1
        state_shape = (capacity, resolution[0], resolution[1], channels)
        self.s1 = np.zeros(state_shape, dtype=np.float32)
        self.s2 = np.zeros(state_shape, dtype=np.float32)
        self.a = np.zeros(capacity, dtype=np.int32)
        self.r = np.zeros(capacity, dtype=np.float32)
        self.isterminal = np.zeros(capacity, dtype=np.float32)

        self.capacity = capacity
        self.size = 0
        self.pos = 0

    def add_transition(self, s1, action, s2, isterminal, reward):
        self.s1[self.pos, :, :, 0] = s1
        self.a[self.pos] = action
        if not isterminal:
            self.s2[self.pos, :, :, 0] = s2
        self.isterminal[self.pos] = isterminal
        self.r[self.pos] = reward

        self.pos = (self.pos + 1) % self.capacity
        self.size = min(self.size + 1, self.capacity)

    def get_sample(self, sample_size):
        i = sample(range(0, self.size), sample_size)
        return self.s1[i], self.a[i], self.s2[i], self.isterminal[i], self.r[i]



#네트워크 만들기
class DQN:
    def __init__(self,session, available_actions_count):
        # Create the input variables
        self.imageIn = tf.placeholder(tf.float32, [None] + list(resolution) + [1], name="State")
        self.target_q_ = tf.placeholder(tf.float32, [None, available_actions_count], name="TargetQ")

        self.keep_prob=tf.placeholder(tf.float32)

        #dropout_p = tf.placeholder(tf.float32,name="dropout_p")

        # 2개의convolutional 레이어 추가
        self.conv1 = tf.contrib.layers.convolution2d(self.imageIn, num_outputs=8, kernel_size=[6, 6], stride=[3, 3],
                                                activation_fn=tf.nn.relu,
                                                weights_initializer=tf.contrib.layers.xavier_initializer_conv2d(),
                                                biases_initializer=tf.constant_initializer(0.1))
        self.conv2 = tf.contrib.layers.convolution2d(self.conv1, num_outputs=8, kernel_size=[3, 3], stride=[2, 2],
                                                activation_fn=tf.nn.relu,
                                                weights_initializer=tf.contrib.layers.xavier_initializer_conv2d(),
                                                biases_initializer=tf.constant_initializer(0.1))
        self.conv2_flat = tf.contrib.layers.flatten(self.conv2)



        # Fully Connected 레이어입니다
        self.FC1 = tf.contrib.layers.fully_connected(self.conv2_flat, num_outputs=320, activation_fn=tf.nn.relu,
                                                weights_initializer=tf.contrib.layers.xavier_initializer(),
                                                biases_initializer=tf.constant_initializer(0.1))

        self.FC1=tf.nn.dropout(self.FC1,keep_prob=self.keep_prob)


        #액션의 갯수만큼 q아웃풋이 나옵니다.
        self.q = tf.contrib.layers.fully_connected(self.FC1, num_outputs=available_actions_count, activation_fn=None,
                                              weights_initializer=tf.contrib.layers.xavier_initializer(),
                                              biases_initializer=tf.constant_initializer(0.1))

        #q아웃풋에서 액션을 결정
        self.best_a = tf.argmax(self.q, 1)

        #loss를 계산합니다
        self.loss = tf.contrib.losses.mean_squared_error(self.q, self.target_q_)
        self.loss_summ = tf.summary.scalar('loss',self.loss)

        #Optimier과정
        self.optimizer = tf.train.RMSPropOptimizer(learning_rate)

        # loss를 줄입니다
        self.train_step = self.optimizer.minimize(self.loss)


    def function_learn(self,s1, target_q):
        self.feed_dict = {self.imageIn: s1, self.target_q_: target_q, self.keep_prob: 0.7}
        s,l, _ = session.run([summary,self.loss, self.train_step], feed_dict=self.feed_dict)
        writer.add_summary(s, global_step=epoch)
        return l

    def function_get_q_values(self,state):
        return session.run(self.q, feed_dict={self.imageIn: state, self.keep_prob: 1})

    def function_get_best_action(self,state):
        return session.run(self.best_a, feed_dict={self.imageIn: state, self.keep_prob: 1})

    def function_simple_get_best_action(self,state):
        return self.function_get_best_action(state.reshape([1, resolution[0], resolution[1], 1]))[0]

        #학습함수, Q값, 행동반환


#메모리에서 자료를 가져와 학습하는 함수입니다. 밑에 perform_learning_step에서 쓰입니다.
def learn_from_memory():

    # 배치사이즈만큼 차면 러닝을 시작합니다.
    if memory.size > batch_size:
        s1, a, s2, isterminal, r = memory.get_sample(batch_size)

        q2 = np.max(mainDQN.function_get_q_values(s2), axis=1)
        target_q = mainDQN.function_get_q_values(s1)

        # Q값을 계산하고 업데이트합니다
        target_q[np.arange(target_q.shape[0]), a] = r + discount_factor * (1 - isterminal) * q2
        mainDQN.function_learn(s1, target_q)


#학습을 수행하는 함수입니다.
def perform_learning_step(epoch):

    #입실론값을 설정합니다
    def exploration_rate(epoch):
        start_eps = 1.0
        end_eps = 0.1
        const_eps_epochs = 0.1 * epochs  # 10% of learning time
        eps_decay_epochs = 0.6 * epochs  # 60% of learning time

        if epoch < const_eps_epochs:
            return start_eps
        elif epoch < eps_decay_epochs:
            return start_eps - (epoch - const_eps_epochs) / \
                               (eps_decay_epochs - const_eps_epochs) * (start_eps - end_eps)
        else:
            return end_eps

    s1 = preprocess(game.get_state().screen_buffer)

    # 랜덤한 행동을 할지 결정합니다
    eps = exploration_rate(epoch)
    if random() <= eps:
        a = randint(0, len(actions) - 1)
    else:
        # 메인DQN에서 행동을 택합니다
        a = mainDQN.function_simple_get_best_action(s1)
    reward = game.make_action(actions[a], frame_repeat)

    isterminal = game.is_episode_finished()
    s2 = preprocess(game.get_state().screen_buffer) if not isterminal else None



    # 메모리에 넣어줍니다.
    memory.add_transition(s1, a, s2, isterminal, reward)
    #메모리에서 자료를 꺼내 러닝합니다
    learn_from_memory()


#메인 함수입니다.
if __name__ == '__main__':
    # 둠 초기설정
    game = initialize_vizdoom(config_file_path)

    # 가능한 버튼갯수, 액션을 받습니다.
    nOfAction = game.get_available_buttons_size()
    actions = [list(a) for a in it.product([0, 1], repeat=nOfAction)]

    #저장할 메모리를 만듭니다
    memory = ReplayMemory(replay_memory_size)




    #세션을 엽니다
    session = tf.Session()
    mainDQN = DQN(session,len(actions))
    saver = tf.train.Saver()

    summary = tf.summary.merge_all()
    writer = tf.summary.FileWriter('./logs')
    writer.add_graph(session.graph)

    #모델 로드
    if load_model:
        print("Loading model from: ", model_savefile)
        saver.restore(session, model_savefile)
    else:
        init = tf.initialize_all_variables()
        session.run(init)
    print("Starting the training!")


    time_start = time()
    if not skip_learning:

        #epoch시작
        for epoch in range(epochs):
            print("\nEpoch %d\n-------" % (epoch + 1))
            train_episodes_finished = 0
            train_scores = []

            print("Training...")
            game.new_episode()

            #epoch당 반복되는 횟수를 받아 반복합니다
            for learning_step in trange(learning_steps_per_epoch):
                episode_buff=[]
                perform_learning_step(epoch)
                if game.is_episode_finished():
                    score = game.get_total_reward()
                    train_scores.append(score)
                    game.new_episode()
                    train_episodes_finished += 1

            print("%d training episodes played." % train_episodes_finished)

            train_scores = np.array(train_scores)

            print("Results: mean: %.1f±%.1f," % (train_scores.mean(), train_scores.std()),
                  "min: %.1f," % train_scores.min(), "max: %.1f," % train_scores.max())





            print("\nTesting...")

            test_episode = []
            test_scores = []
            for test_episode in trange(test_episodes_per_epoch):
                game.new_episode()
                while not game.is_episode_finished():
                    state = preprocess(game.get_state().screen_buffer)
                    best_action_index = mainDQN.function_simple_get_best_action(state)

                    game.make_action(actions[best_action_index], frame_repeat)
                r = game.get_total_reward()
                test_scores.append(r)

            test_scores = np.array(test_scores)
            print("Results: mean: %.1f±%.1f," % (
                test_scores.mean(), test_scores.std()), "min: %.1f" % test_scores.min(),
                  "max: %.1f" % test_scores.max())

            print("Saving the network weigths to:", model_savefile)
            saver.save(session, model_savefile)

            print("Total elapsed time: %.2f minutes" % ((time() - time_start) / 60.0))

    game.close()
    print("======================================")
    print("Training finished. It's time to watch!")


    # 최종 학습결과를 보여주는 부분입니다
    game.set_window_visible(True)
    game.set_mode(Mode.ASYNC_PLAYER)
    game.init()

    for _ in range(episodes_to_watch):
        game.new_episode()
        while not game.is_episode_finished():
            state = preprocess(game.get_state().screen_buffer)
            best_action_index = mainDQN.function_simple_get_best_action(state)

            game.set_action(actions[best_action_index])
            for _ in range(frame_repeat):
                game.advance_action()

        sleep(1.0)
        score = game.get_total_reward()
        print("Total score: ", score)
