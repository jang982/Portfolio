#pragma once

#include <iostream>
#include <string>
#include <list>
#include<ctime>

using namespace std;

//Class: Timer
//Description: Time 헤더
//created: 2017/5/24 20:00pm
//Author: 홍유남
//mail: bcdass@naver.com

//Class: Timer
//Description: Time 헤더 함수 추가
//created: 2017/5/31 10:00pm
//Author: 홍유남
//mail: bcdass@naver.com

// Revsions : 
//   1. When & Who :  2017/6/1 15:00pm    김윤영
//   2.   What :   void sortVote(VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote);
//               void  stringTimeTointTime(string time, int* result);, int    intTimeToMinute(int* intTime);
//               총 3가지 함수 구현

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
	//Description: 시간이 바뀔때 사용하고 vote가 현재, 향후 진행, 과거 투표인지 구분해서 각각의 collection에 넣어주는 기능 
	//Parameters: VoteCollection* currentVote, VoteCollection* postVote, VoteCollection* preVote
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	void			stringTimeTointTime(string time, int* result);
	//Function:    void   stringTimeTointTime(string time, int* result);
	//Description: string 타입으로 되어있는 시간을 intResult[5](year, month, day hour, minute)
	//Parameters: string time, int* result
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	int				intTimeToMinute(int* intTime);
	//Function:    int      intTimeToMinute(int* intTime);
	//Description: intTime[5](year, month, day hour, minute) 를 분으로 바꿔주는 함수.
	//Parameters: int* intTime (year, month, day hour, minute)
	//Return Value: 총 분
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	void			passingTime(string inputTime ,int compare[4]);
	void			compareTime(int compare[4], int input1[4], int input2[4]);
	void			plusTime(int compare[4]);
	bool			deleteVoteMessage(string endTime);
};

