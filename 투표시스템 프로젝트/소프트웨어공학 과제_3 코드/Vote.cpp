#include "Vote.h"
#include "VoteCollection.h"


//Class: 
//Description: 
//created: 2017/5/30 22:00pm
//Author: ȫ����
//mail: bcdass@naver.com

// Function : 
// Description: 
// Parameters : 
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//

// Function : Vote
// Description: �����ڸ� �̿��� vote �ʱ�ȭ
// Parameters : string int string string string
// Return Value : 
//
// Created: 2017/5/24 20:00
// Author: ȫ����
//

Vote::Vote(string subjectOfVote, int numberOfItems, string firstStartTime, string firstEndTime, string groupName)
{
	subject = subjectOfVote;
	for (int i = 0; i < MAX_LIST; i++) {
		if (i < numberOfItems)
			items[i] = 0;
		else
			items[i] = -1;
	}

	startTime = firstStartTime;
	endTime = firstEndTime;
	belongsTo = groupName;

}
Vote::~Vote()
{

}

Vote* Vote::createVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firstEndTime, string groupName)// ��ǥ ����
{
	Vote* newVote = new Vote(subjectOfVote, numberOfItems, firstStartTime, firstEndTime, groupName);
	return newVote;
}
// Function : deleteVote
// Description:  �Ҹ��ڸ� �̿��� �Ҹ� �Լ�
// Parameters : 
// Return Value : 
//
// Created: 2017/5/24 20:00
// Author: ȫ����
//
void Vote::deleteVote()
{
	Vote::~Vote();
}

int Vote::doVoteFor(int itemNuber, string newPersonalNumber)
{
	int i = 0;
	for ( i = 0; personalNumberList[i].size() != 0; i++)
	{
		if (!personalNumberList[i].compare(newPersonalNumber))
		{ //�̹� �����ϴ� ���
			return 1;
		}
	}
	personalNumberList[i] = newPersonalNumber;
	setItems(itemNuber);
	return 2;
}



string Vote::getSubject()
{
	return subject;
}

void Vote::setSubject(string inputSubject)
{
	subject = inputSubject;
}

int Vote::getItems()
{
	int cnt = 0;
	while (items[cnt++] != -1);
	return cnt-1;
}

void Vote::setItems(int inputItems)
{
	items[inputItems - 1]++;
}



string Vote::getStartTime()
{
	return startTime;
}

void Vote::setStartTime(string inputStartTime)
{
	startTime = inputStartTime;
}

string Vote::getEndTime()
{
	return endTime;
}

void Vote::setEndTime(string inputEndTime)
{
	endTime = inputEndTime;
}

string Vote::getBelongsTo()
{
	return belongsTo;
}

void Vote::setBelongsTo(string inputBelongsTo)
{
	belongsTo=inputBelongsTo;
}


int * Vote::getResult()
{
	return items;
}

