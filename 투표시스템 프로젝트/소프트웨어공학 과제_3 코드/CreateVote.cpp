#include "CreateVote.h"
#include "CreateVoteUI.h"
#include "VoteCollection.h"

CreateVote::CreateVote(VoteCollection &voteCollection)
{
	voteCollectionPointer = &voteCollection;
}


CreateVote::~CreateVote()
{
}


bool CreateVote::createVote(string newSubject, int numberOfItems, string newStartTime, string newEndTime, string groupName)
{
	// 누락된 항목이 있을 경우
	if (newSubject.size() == 0 && numberOfItems == 0 && newStartTime.size() == 0 && newEndTime.size() == 0)
		return true;
	else {
		voteCollectionPointer->addVote(newSubject, numberOfItems, newStartTime, newEndTime,groupName);
		return false;
		}
	
}

CreateVoteUI * CreateVote::callCreateVoteUIStartInterface(CreateVote & createVote)
{
	return CreateVoteUI::startInterface(createVote);
}
