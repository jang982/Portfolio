#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class VoteFor;
//Class: VoteForUI
//Description: ��ǥ ���(VoteFor)�� boundary Ŭ���� ������ ������.
//created: 2017/6/1 15:00pm
//Author: ������
//mail: kyy01114@hanmail.net

class VoteForUI
{
private:
	VoteFor* voteForPointer;

public:
	static VoteForUI* startInterface(VoteFor &voteFor);
	//Function: static VoteForUI* startInterface(VoteFor &voteFor);
	//Description: control class�� ���� startinterface�� ����ȴ�.
	//Parameters: VoteFor& voteFor - ��ǥ ���(votefor)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm

	int inputData(string subject, int itemNumber,string joinedGroup, string personalNumber);
	//Function: int inputData(string subject, int itemNumber,string joinedGroup, string personalNumber)
	//Description: �ʿ��� �����͸� control�� �ѱ�� ����� �����Ѵ�.
	//Parameters: VoteFor& voteFor - ��ǥ ���(votefor)�� control class
	//Return Value: error value, 2���� error�� 1���� ����, �� 3������ �����ϱ� ���� int�� ���
	//Author: ������
	//Created: 2017/6/1 15:00pm

	VoteForUI(VoteFor &voteFor);
	~VoteForUI();
	//Function: VoteForUI(VoteFor &voteFor), ~VoteForUI()
	//Description: �����ڿ� �Ҹ���, UI�� control�� ���� �����ȴ�.
	//Parameters: VoteFor& voteFor - ��ǥ ���(votefor)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm
};

