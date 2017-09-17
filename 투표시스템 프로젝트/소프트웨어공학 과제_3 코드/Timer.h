#pragma once

#include <iostream>
#include <string>
#include <list>
#include<ctime>

using namespace std;

//Class: Timer
//Description: Time ���
//created: 2017/5/24 20:00pm
//Author: ȫ����
//mail: bcdass@naver.com

//Class: Timer
//Description: Time ��� �Լ� �߰�
//created: 2017/5/31 10:00pm
//Author: ȫ����
//mail: bcdass@naver.com

// Revsions : 
//   1. When & Who :  2017/6/1 15:00pm    ������
//   2.   What :   void sortVote(VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote);
//               void  stringTimeTointTime(string time, int* result);, int    intTimeToMinute(int* intTime);
//               �� 3���� �Լ� ����

#define MAX_STRING 50
class Timer;
class VoteCollection;
class Vote;



class Timer{
private:
	char currentTime[MAX_STRING];
	int year;
	int month;
	int day;
	int hour;
	int minute;
	
	list<Vote> allVoteList;

public:
	Timer();
	~Timer();

	void			setTime(string inputTime);
	string			getTime();
	void			sortVote(VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote);
	//Function   :void sortVote(VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote);
	//Description: �ð��� �ٲ� ����ϰ� vote�� ����, ���� ����, ���� ��ǥ���� �����ؼ� ������ collection�� �־��ִ� ��� 
	//Parameters: VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote
	//Author: ������
	//Created: 2017/6/1 15:00pm

	void			stringTimeTointTime(string time, int* result);
	//Function:    void   stringTimeTointTime(string time, int* result);
	//Description: string Ÿ������ �Ǿ��ִ� �ð��� intResult[5](year, month, day hour, minute)
	//Parameters: string time, int* result
	//Author: ������
	//Created: 2017/6/1 15:00pm

	int				intTimeToMinute(int* intTime);
	//Function:    int      intTimeToMinute(int* intTime);
	//Description: intTime[5](year, month, day hour, minute) �� ������ �ٲ��ִ� �Լ�.
	//Parameters: int* intTime (year, month, day hour, minute)
	//Return Value: �� ��
	//Author: ������
	//Created: 2017/6/1 15:00pm

	void			passingTime(string inputTime ,int compare[4]);
	void			compareTime(int compare[4], int input1[4], int input2[4]);
	void			plusTime(int compare[4]);
	bool			deleteVoteMessage(string endTime);
};

