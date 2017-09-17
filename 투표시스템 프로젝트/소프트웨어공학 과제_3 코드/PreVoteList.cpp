#include "PreVoteList.h"
#include "PreVoteListUI.h"
#include "Vote.h"
#include "Group.h"
#include "VoteCollection.h"
#include"GroupCollection.h"

PreVoteList::PreVoteList(VoteCollection &voteCollection)
{
	voteCollectionPointer = &voteCollection;
}


PreVoteList::~PreVoteList()
{
}

// Function : showVoteList
// Description:  Vote의 정보 전달을 위한 함수
// Parameters : string* int* string* string* string* int**
// Return Value : 
// Created: 2017/5/24 11:50pm
// Author: 홍유남
//

void PreVoteList::showVoteList(string * subject, int * items, string * startTime, string * endTime, string * belongsTo, int** result)
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
		belongsTo[i] = iter->getBelongsTo();
		result[i++] = iter->getResult();
		voteCollectionPointer->getNext(iter);
	}
}

PreVoteListUI * PreVoteList::getPreVoteListUIPointer()
{
	return preVoteListUIPointer;
}
// Function : deleteVoteMessage
// Description:  투표 삭제를 위한 함수 timer로부터 온 endtime을 지우라는 것을 투표리스트에 보낸다
// Parameters : string
// Return Value : 
// Created: 2017/5/24 11:50pm
// Author: 홍유남
//
void PreVoteList::deleteVoteMessage(string endTime)
{
	list<Vote>::iterator iter = voteCollectionPointer->findFirst();
	list<Vote>::iterator iterEnd = voteCollectionPointer->findEnd();

	int i = 0;
	while (iter != iterEnd)
	{
		if (endTime == iter->getEndTime()) {
			iter->deleteVote();
		}
		voteCollectionPointer->getNext(iter);
	}

}
// Function : callPreVoteListUIStartInterface
// Description:  startInterface 를 불러오는 함수
// Parameters : PreVOteList&
// Return Value :  PreVoteListUI::startInterface()
// Created: 2017/5/24 11:50pm
// Author: 홍유남
//
PreVoteListUI *PreVoteList::callPreVoteListUIStartInterface(PreVoteList & preVoteList)
{
	return PreVoteListUI::startInterface(preVoteList);
}
