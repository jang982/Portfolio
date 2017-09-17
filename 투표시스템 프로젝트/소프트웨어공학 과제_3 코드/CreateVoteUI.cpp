#include "CreateVoteUI.h"
#include "CreateVote.h"


CreateVoteUI::CreateVoteUI(CreateVote & createVote)
{
	createVotePointer = &createVote;
}

CreateVoteUI::~CreateVoteUI()
{
}


CreateVoteUI * CreateVoteUI::startInterface(CreateVote & createVote)
{
	CreateVoteUI* newPointer = new CreateVoteUI(createVote);
	return newPointer;
}

bool CreateVoteUI::inputDate(string newSubject, int numberOfItems, string newStartTIme, string newEndTime, string groupName)
{
	return createVotePointer->createVote(newSubject, numberOfItems, newStartTIme, newEndTime,groupName);
}

