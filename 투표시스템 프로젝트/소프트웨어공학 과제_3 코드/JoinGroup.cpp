#include "JoinGroup.h"
#include "JoinGroupUI.h"
#include "UserCollection.h"
#include "GroupCollection.h"
#include "User.h"
#include "Group.h"

//Class: JoinGroup
//Description: JoinGroup ����
//created: 2017/5/26 21:10pm
//Author: ������
//mail: jang8018@naver.com


// Function : JoinGroup(GroupCollection &groupCollection, UserCollection &userCollection)
// Description: �׷��ݷ��ǰ� �����ݷ����ּҸ� �޾� �����͸� �����ϰ�, ��Ʈ���� �����մϴ�.
// Parameters : GroupCollection &groupCollection, UserCollection &userCollection
// Return Value : void
//
// Created: 2017/5/26 21:10pm
// Author: ������
//
JoinGroup::JoinGroup(GroupCollection &groupCollection, UserCollection &userCollection)
{
	groupCollectionPointer = &groupCollection;
	userCollectionPointer = &userCollection;
}


JoinGroup::~JoinGroup()
{
}

// Function : callJoinGroupUIStartInterface(JoinGroup & joinGroup)
// Description: �׷찡�� ��Ʈ���� �޾ƿͼ� UI������ ���մϴ�.
// Parameters : JoinGroup & joinGroup
// Return Value : JoinGroupUI *
//
// Created: 2017/5/26 21:12pm
// Author: ������
//
JoinGroupUI * JoinGroup::callJoinGroupUIStartInterface(JoinGroup & joinGroup)
{
	return JoinGroupUI::startInterface(joinGroup);
}


// Function : joinGroup(string group_name, list<User>::iterator loginUser)
// Description: �α������� ������ �ݺ��ڿ� �׷��̸��� �޾ƿ� �׷쿡 ���Խ�ŵ�ϴ�.
// Parameters : string group_name, list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/26 21:13pm
// Author: ������
//
bool JoinGroup::joinGroup(string group_name, list<User>::iterator loginUser)
{
	list<Group>::iterator iter = groupCollectionPointer->findGroup(group_name);

	if (iter == groupCollectionPointer->findEnd())
	{
		return true;
	}
	else
	{
		loginUser->setJoinedGroup(group_name);
		return false;
	}
	
}
