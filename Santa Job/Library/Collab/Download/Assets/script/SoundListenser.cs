using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class SoundListenser : MonoBehaviour {

    public AudioSource BGM;
    public AudioSource footStepSFX;
    public AudioSource AttackSFX;
    public AudioSource HittedSFX;

    GameObject Player;
    Animator animator;

    void Start()
    {
        if (SceneManager.GetActiveScene().buildIndex == 0 || SceneManager.GetActiveScene().name =="Reward")
            return;
        animator = GameObject.FindGameObjectWithTag("Player").GetComponent<Animator>();
        Player = GameObject.FindGameObjectWithTag("Player");
    }

    public void initializeSoundListener()
    {
        Start();
    }

    //리스너 위치를 플레이어쪽으로 이동시킵니다
    void FixedUpdate () {
        if (SceneManager.GetActiveScene().buildIndex == 0 || SceneManager.GetActiveScene().name=="Reward")
            return;

        this.transform.position = Player.transform.position;
	}

    public void playBGM(AudioClip bgm)
    {
        BGM.clip = bgm;
        BGM.loop = true;
        BGM.Play();
    }

    //발자국소리를 받아 재생합니다
    public void playFootStepSound(AudioClip audio)
    {
        footStepSFX.clip = audio;
        footStepSFX.Play();
    }

    public void playAttackSound(AudioClip audio)
    {
        AttackSFX.clip = audio;
        AttackSFX.Play();
    }

    public void playHittedSound(AudioClip audio)
    {
        HittedSFX.clip = audio;
        HittedSFX.volume = 0.5f;
        HittedSFX.Play();
    }
}
