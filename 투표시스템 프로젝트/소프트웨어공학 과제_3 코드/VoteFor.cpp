#include "VoteFor.h"
#include "VoteForUI.h"
#include "Vote.h"
#include "VoteCollection.h"


VoteFor::VoteFor(VoteCollection &voteCollection)
{
	voteCollectionPointer = &voteCollection;
}


VoteFor::~VoteFor()
{
}

int VoteFor::doVote(string subject, int itemNumber, string joinedGroup, string personalNumber)
{
	list<Vote>::iterator iter = voteCollectionPointer->findFirst();
	while (iter != voteCollectionPointer->findEnd())
	{
		if (!joinedGroup.compare(iter->getBelongsTo()))
		{
			//그룹 내의 vote에서
			if (!subject.compare(iter->getSubject()))
			{
				// 주제가 같은 것이 있다면
				if (itemNumber <= iter->getItems())
				{
					// 존재하는 항목 번호 인경우
					return iter->doVoteFor(itemNumber,personalNumber);
				}
			}
		}
		iter++;
	}

	return 0; //에러가 있음

}

VoteForUI * VoteFor::callVoteForUIStartInterface(VoteFor & voteFor)
{
	return VoteForUI::startInterface(voteFor);
}
