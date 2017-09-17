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
// Description: ��ǥ ����Ʈ�� ù��° ���� �޾ƞ��ϴ�
// Parameters : 
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//

list<Vote>::iterator VoteCollection::findFirst()
{
	voteListIterator = voteList.begin();
	return voteListIterator;
}
// Function : findEnd
// Description: ��ǥ����Ʈ�� ������ �޾ƿɴϴ�.
// Parameters : 
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//

list<Vote>::iterator VoteCollection::findEnd()
{
	voteListIterator = voteList.end();
	return voteListIterator;
}
// Function :  getNext
// Description:  iterator�� ���� ��ǥ ����Ʈ�� ����ġ�� �մϴ�.
// Parameters : iterator
// Return Value : iterator
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//
list<Vote>::iterator VoteCollection::getNext(list<Vote>::iterator &inputIter)
{
	return inputIter++;
}

// Function :  addVote
// Description: ����Ʈ�� ��ǥ�� �߰��մϴ�
// Parameters : string , int , string, string, string
// Return Value : 
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//
void VoteCollection::addVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firsrEndTime, string groupName)
{
	voteList.push_back(*Vote::createVote(subjectOfVote, numberOfItems, firstStartTime, firsrEndTime,groupName));
}

// Function : getVoteListHead
// Description: ��ǥ����Ʈ�� �ּҰ��� �޾ƿɴϴ�.
// Parameters : 
// Return Value : &list
//
// Created: 2017/5/30 22:00pm
// Author: ȫ����
//

list<Vote>* VoteCollection::getVoteListHead()
{
	return &voteList;
}
