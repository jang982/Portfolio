#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;
class VoteForUI;
class VoteCollection;

//Class: VoteFor
//Description: ��ǥ ���(VoteFor)�� control Ŭ���� ������ ������.
//created: 2017/6/1 15:00pm
//Author: ������
//mail: kyy01114@hanmail.net

class VoteFor
{
private:
	VoteCollection* voteCollectionPointer;
	VoteForUI* voteForUIPointer;

public:
	VoteFor(VoteCollection &voteCollection);
	~VoteFor();
	//Function: VoteFor(VoteCollection &voteCollection), ~VoteFor()
	//Description: �����ڿ� �Ҹ���, ��ǥ(voteFor) control class�� votecollection�� ���۷����� ������ �־���Ѵ�.
	//Parameters: VoteCollection &voteCollection - ��ǥ collection
	//Author: ������
	//Created: 2017/6/1 15:00pm

	int doVote(string subject, int itemNumber, string joinedGroup, string personalNumber);
	//Function: int doVote(string subject, int itemNumber, string joinedGroup, string personalNumber);
	//Description: vote�� �ִ� dovotefor�� ���� ���� error���� �ɷ��ش�.
	//Parameters: string subject - ��ǥ ����, int itemNumber - ��ǥ�ϴ� �׸��ȣ, string joinedGroup - ������ ���Ե� �׷�, string personalNumber - ������ �ֹι�ȣ
	//Return Value: error value, error�� 2���� error�� ������ �����ϱ� ���� int�� ���
	//Author: ������
	//Created: 2017/6/1 15:00pm
	
	VoteForUI* callVoteForUIStartInterface(VoteFor &voteFor);
	//Function: VoteForUI* callVoteForUIStartInterface(VoteFor &voteFor);
	//Description: control class�� �Է� �ޱ��� UI�� �����ؾߵȴ�.
	//Parameters: VoteFor& voteFor - ��ǥ ���(votefor)�� control class
	//Author: ������
	//Created: 2017/6/1 15:00pm
};

