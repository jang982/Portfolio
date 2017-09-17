#pragma once
#include<iostream>
#include<list>
#include<string>

using namespace std;

class VoteCollection;
class CreateVoteUI;

//Class: CreateVote
//Description: 투표 제안 기능(createVote)의 contorl 클래스 역할을 수행함.
//created: 2017/6/1 15:00pm
//Author: 김윤영
//mail: kyy01114@hanmail.net

class CreateVote
{
private:
	VoteCollection* voteCollectionPointer;
	CreateVoteUI* createVoteUIPointer;

	bool isExist;
public:

	bool createVote(string newSubject,int numberOfItems, string newStartTime,string newEndTime, string groupName);
	//Function:   bool createVote(string newSubject,int numberOfItems, string newStartTime,string newEndTime, string groupName);
	//Description: createvote를 위한 input를 votecollection으로 전달해준다.
	//Parameters: (string newSubject,int numberOfItems, string newStartTime,string newEndTime, string groupName
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	CreateVoteUI* callCreateVoteUIStartInterface(CreateVote &createVote);
	//Function:   CreateVoteUI* callCreateVoteUIStartInterface(CreateVote &createVote);
	//Description: control class는 입력 받기전 UI를 생성해야된다.
	//Parameters: CreateVote &createVote -  투표 제안 기능(createVote)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	CreateVote(VoteCollection &voteCollection);
	~CreateVote();
	//Function:   CreateVote(VoteCollection &voteCollection);   ~CreateVote();
	//Description: 생성자와 소멸자,  투표 제안 기능(createVote) control class는 votecollection의 레퍼런스를 가지고 있어야한다.
	//Parameters: VoteCollection &voteCollection - 투표 collection
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm
};

