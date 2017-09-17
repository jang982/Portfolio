#include "Vote.h"
#include "VoteCollection.h"


//Class: 
//Description: 
//created: 2017/5/30 22:00pm
//Author: 홍유남
//mail: bcdass@naver.com

// Function : 
// Description: 
// Parameters : 
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

// Function : Vote
// Description: 생성자를 이용한 vote 초기화
// Parameters : string int string string string
// Return Value : 
//
// Created: 2017/5/24 20:00
// Author: 홍유남
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

Vote* Vote::createVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firstEndTime, string groupName)// 투표 생성
{
	Vote* newVote = new Vote(subjectOfVote, numberOfItems, firstStartTime, firstEndTime, groupName);
	return newVote;
}
// Function : deleteVote
// Description:  소멸자를 이용한 소멸 함수
// Parameters : 
// Return Value : 
//
// Created: 2017/5/24 20:00
// Author: 홍유남
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
		{ //이미 존재하는 경우
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

