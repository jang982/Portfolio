#include "ShowAllGroup.h"
#include "ShowAllGroupUI.h"
#include "Group.h"
#include "User.h"
#include "UserCollection.h"
#include "GroupCollection.h"



//Class: ShowAllGroup
//Description: ShowAllGroup ����
//created: 2017/5/29 08:20am
//Author: ������
//mail: jang8018@naver.com


// Function : ShowAllGroup(GroupCollection &groupCollection)
// Description: �׷��ݷ����ּҸ� �޾� ��Ʈ���� �����մϴ�.
// Parameters : GroupCollection &groupCollection
// Return Value : void
//
// Created: 2017/5/29 08:20am
// Author: ������
//
ShowAllGroup::ShowAllGroup(GroupCollection &groupCollection)
{
	groupColletionPointer = &groupCollection;
}


ShowAllGroup::~ShowAllGroup()
{
}


// Function : showAllGroup(string* groupList)
// Description: ���ڿ� �迭�� �޾� �׷츮��Ʈ���� �׷�����޾� �����մϴ�.
// Parameters : string* groupList
// Return Value : void
//
// Created: 2017/5/29 08:25am
// Author: ������
//
void ShowAllGroup::showAllGroup(string* groupList)
{
	list<Group>::iterator iter = groupColletionPointer->findFirst();
	list<Group>::iterator iterEnd = groupColletionPointer->findEnd();

	int i = 0;
	while (iter != iterEnd)
	{
		groupList[i++]=iter->getGroupName();
		groupColletionPointer->getNext(iter);
	}


}


// Function : callShowAllGroupUIStartInterface(ShowAllGroup &showAllGroup)
// Description: UI�� �������̽��� ȣ���մϴ�.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : ShowAllGroupUI*
//
// Created: 2017/5/29 08:30am
// Author: ������
//
ShowAllGroupUI* ShowAllGroup::callShowAllGroupUIStartInterface(ShowAllGroup &showAllGroup)
{
	return ShowAllGroupUI::startInterface(showAllGroup);
}
