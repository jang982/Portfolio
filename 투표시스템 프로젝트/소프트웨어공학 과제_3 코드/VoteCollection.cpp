#include "Vote.h"
#include "VoteCollection.h"

using namespace std;

VoteCollection::VoteCollection()
{
}
VoteCollection::~VoteCollection()
{
}
// Function : findFirst
// Description: 투표 리스트의 첫번째 값을 받아옶니다
// Parameters : 
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

list<Vote>::iterator VoteCollection::findFirst()
{
	voteListIterator = voteList.begin();
	return voteListIterator;
}
// Function : findEnd
// Description: 투표리스트의 끝값을 받아옵니다.
// Parameters : 
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

list<Vote>::iterator VoteCollection::findEnd()
{
	voteListIterator = voteList.end();
	return voteListIterator;
}
// Function :  getNext
// Description:  iterator를 다음 투표 리스트를 가르치게 합니다.
// Parameters : iterator
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//
list<Vote>::iterator VoteCollection::getNext(list<Vote>::iterator &inputIter)
{
	return inputIter++;
}

// Function :  addVote
// Description: 리스트에 투표를 추가합니다
// Parameters : string , int , string, string, string
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//
void VoteCollection::addVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firsrEndTime, string groupName)
{
	voteList.push_back(*Vote::createVote(subjectOfVote, numberOfItems, firstStartTime, firsrEndTime,groupName));
}

// Function : getVoteListHead
// Description: 투표리스트의 주소값을 받아옵니다.
// Parameters : 
// Return Value : &list
//
// Created: 2017/5/30 22:00pm
// Author: 홍유남
//

list<Vote>* VoteCollection::getVoteListHead()
{
	return &voteList;
}
