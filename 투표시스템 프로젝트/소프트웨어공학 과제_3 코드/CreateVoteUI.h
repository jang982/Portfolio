#pragma once
#include<iostream>
#include<list>
#include<string>

using namespace std;

class Vote;
class CreateVote;
//Class: CreateVoteUI
//Description: ��ǥ ���� ���(createVote)�� boundary Ŭ���� ������ ������.
//created: 2017/6/1 15:00pm
//Author: ������
//mail: kyy01114@hanmail.net

class CreateVoteUI
{
private:
	CreateVote* createVotePointer;

public:
	static CreateVoteUI* startInterface(CreateVote &createVote);
	//Function: static CreateVoteUI* startInterface(CreateVote &createVote);
	//Description: UI�� control class���� ����ȴ�.
	//Parameters: CreateVote &createVote - ��ǥ ���� ���(createVote)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm

	bool inputDate(string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName);
	//Function: bool inputDate(string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName);
	//Description: �ʿ��� �����͸� control�� �ѱ�� ����� �����Ѵ�.
	//Parameters: string newSubject,int numberOfItems,string newStartTIme, string newEndTime,string groupName == ��ǥ ������ �ʿ��� data��
	//Return Value: error value, �������� error���� ����.
	//Author: ������
	//Created: 2017/6/1 15:00pm

	CreateVoteUI(CreateVote &createVote);
	~CreateVoteUI();
	//Function: CreateVoteUI(CreateVote &createVote);   ~CreateVoteUI();
	//Description: �����ڿ� �Ҹ���, UI�� control�� ���� �����ȴ�.
	//Parameters: CreateVote &createVote - ��ǥ ���� ���(createVote)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm
};

