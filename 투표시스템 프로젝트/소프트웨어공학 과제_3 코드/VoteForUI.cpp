#include "VoteForUI.h"
#include "VoteFor.h"

VoteForUI::VoteForUI(VoteFor &voteFor)
{
	voteForPointer = &voteFor;
}
VoteForUI::~VoteForUI()
{
}


VoteForUI * VoteForUI::startInterface(VoteFor & voteFor)
{
	VoteForUI* newPointer = new VoteForUI(voteFor);
	return newPointer;
}

int VoteForUI::inputData(string subject, int itemNumber,string joinedGroup, string personalNumber)
{
	return voteForPointer->doVote(subject,itemNumber,joinedGroup,personalNumber);
}

