#include "PostVoteList.h"
#include "PostVoteListUI.h"
#include "Vote.h"
#include "Group.h"
#include "VoteCollection.h"
#include"GroupCollection.h"

PostVoteList::PostVoteList(VoteCollection &voteCollection)
{
	voteCollectionPointer = &voteCollection;
}


PostVoteList::~PostVoteList()
{
}

// Function : showVoteList
// Description:  Vote의 정보 전달을 위한 함수
// Parameters : string* int* string* string* string*
// Return Value : 
// Created: 2017/5/24 12:50pm
// Author: 홍유남
//

void PostVoteList::showVoteList(string * subject, int * items, string * startTime, string * endTime,string * belongsTo)
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

PostVoteListUI * PostVoteList::getPostVoteListUIPointer()
{
	return postVoteListUIPointer;
}


PostVoteListUI *PostVoteList::callPostVoteListUIStartInterface(PostVoteList & postVoteList)
{
	return PostVoteListUI::startInterface(postVoteList);
}
