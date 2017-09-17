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
			//�׷� ���� vote����
			if (!subject.compare(iter->getSubject()))
			{
				// ������ ���� ���� �ִٸ�
				if (itemNumber <= iter->getItems())
				{
					// �����ϴ� �׸� ��ȣ �ΰ��
					return iter->doVoteFor(itemNumber,personalNumber);
				}
			}
		}
		iter++;
	}

	return 0; //������ ����

}

VoteForUI * VoteFor::callVoteForUIStartInterface(VoteFor & voteFor)
{
	return VoteForUI::startInterface(voteFor);
}
