#pragma once
#include<iostream>
#include<list>
#include<string>

using namespace std;

class Vote;
class CreateVote;
//Class: CreateVoteUI
//Description: 투표 제안 기능(createVote)의 boundary 클래스 역할을 수행함.
//created: 2017/6/1 15:00pm
//Author: 김윤영
//mail: kyy01114@hanmail.net

class CreateVoteUI
{
private:
	CreateVote* createVotePointer;

public:
	static CreateVoteUI* startInterface(CreateVote &createVote);
	//Function: static CreateVoteUI* startInterface(CreateVote &createVote);
	//Description: UI는 control class에서 실행된다.
	//Parameters: CreateVote &createVote - 투표 제안 기능(createVote)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	bool inputDate(string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName);
	//Function: bool inputDate(string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName);
	//Description: 필요한 데이터를 control로 넘기는 기능을 수행한다.
	//Parameters: string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName == 투표 생성시 필요한 data들
	//Return Value: error value, 성공인지 error인지 구분.
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	CreateVoteUI(CreateVote &createVote);
	~CreateVoteUI();
	//Function: CreateVoteUI(CreateVote &createVote);   ~CreateVoteUI();
	//Description: 생성자와 소멸자, UI는 control에 의해 생성된다.
	//Parameters: CreateVote &createVote - 투표 제안 기능(createVote)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm
};

