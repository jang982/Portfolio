#pragma once
#include<iostream>
#include<list>
#include<string>

using namespace std;

class VoteCollection;
class CreateVoteUI;

//Class: CreateVote
//Description: ��ǥ ���� ���(createVote)�� contorl Ŭ���� ������ ������.
//created: 2017/6/1 15:00pm
//Author: ������
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
	//Description: createvote�� ���� input�� votecollection���� �������ش�.
	//Parameters: (string newSubject,int numberOfItems, string newStartTime,string newEndTime, string groupName
	//Author: ������
	//Created: 2017/6/1 15:00pm

	CreateVoteUI* callCreateVoteUIStartInterface(CreateVote &createVote);
	//Function:   CreateVoteUI* callCreateVoteUIStartInterface(CreateVote &createVote);
	//Description: control class�� �Է� �ޱ��� UI�� �����ؾߵȴ�.
	//Parameters: CreateVote &createVote -  ��ǥ ���� ���(createVote)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm

	CreateVote(VoteCollection &voteCollection);
	~CreateVote();
	//Function:   CreateVote(VoteCollection &voteCollection);   ~CreateVote();
	//Description: �����ڿ� �Ҹ���,  ��ǥ ���� ���(createVote) control class�� votecollection�� ���۷����� ������ �־���Ѵ�.
	//Parameters: VoteCollection &voteCollection - ��ǥ collection
	//Author: ������
	//Created: 2017/6/1 15:00pm
};

