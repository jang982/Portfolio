#include "CurrentVoteList.h"
#include "CurrentVoteListUI.h"
#include "Vote.h"
#include "Group.h"
#include "VoteCollection.h"
#include"GroupCollection.h"


CurrentVoteList::CurrentVoteList(VoteCollection &voteCollection)
{
	voteCollectionPointer = &voteCollection;
}

CurrentVoteList::~CurrentVoteList()
{
}
// Function : showVoteList
// Description:  Vote의 정보 전달을 위한 함수
// Parameters : string* int* string* string* string*
// Return Value : 
// Created: 2017/5/24 13:30pm
// Author: 홍유남
//
void CurrentVoteList::showVoteList(string * subject, int * items, string * startTime, string * endTime, string * belongsTo)
{
	list<Vote>::iterator iter = voteCollectionPointer->findFirst();
	list<Vote>::iterator iterEnd = voteCollectionPointer->findEnd();

	int i = 0;
	while (iter != iterEnd)
	{
		subject[i] = iter->getSubject();
		items[i] = iter->getItems();
		startTime[i] = iter->getStartTime();
		endTime[i] = iter->getEndTime();
		belongsTo[i++] = iter->getBelongsTo();
		voteCollectionPointer->getNext(iter);
	}
}

CurrentVoteListUI * CurrentVoteList::callCurrentVoteListUIStartInterface(CurrentVoteList & currentVoteList)
{
	return CurrentVoteListUI::startInterface(currentVoteList);
}

CurrentVoteListUI * CurrentVoteList::getCurrentVoteListUIPointer()
{
	return currentVoteListUIPointer;
}
