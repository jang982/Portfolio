#include "GroupCollection.h"
#include "CreateGroup.h"
#include "CreateGroupUI.h"
#include "Group.h"
#include "User.h"


//Class: CreateGroup
//Description: CreateGroup ����
//created: 2017/5/25 09:00am
//Author: ������
//mail: jang8018@naver.com




// Function : CreateGroup(GroupCollection &groupCollection)
// Description: �׷� �ݷ����ּҸ� �����Ϳ� �Ҵ��մϴ�
// Parameters : GroupCollection &groupCollection
// Return Value : void
//
// Created: 2017/5/25 09:03am
// Author: ������
//
CreateGroup::CreateGroup(GroupCollection &groupCollection)
{
	groupColletionPointer = &groupCollection;
}


CreateGroup::~CreateGroup()
{
}


// Function : callCreateGroup(string nameOfGroup, list<User>::iterator loginUser)
// Description: �׷� �̸��� �޾Ƽ� �ߺ��� üũ�ϰ�, �����մϴ�. �ߺ��̸� �������� ��ȯ�մϴ�.
// Parameters : string nameOfGroup
//				list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/25 09:04am
// Author: ������
//
bool CreateGroup::callCreateGroup(string nameOfGroup, list<User>::iterator loginUser)
{
	if (loginUser->getJoinedGroup() == "none")
	{
		checkExists(nameOfGroup);
		if (isExists)
		{
			return 1;
		}
		else
		{
			groupColletionPointer->addGroup(nameOfGroup);
			loginUser->setGroupLeader();
			loginUser->setJoinedGroup(nameOfGroup);
			return 0;
		}
	}
	else
		return 1;
	
}



// Function : checkExists(string nameOfGroup)
// Description: �ݺ��ڸ� �޾ƿͼ� �ߺ����� �Ǵ��մϴ�.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 09:10am
// Author: ������
//
void CreateGroup::checkExists(string nameOfGroup)
{
	list<Group>::iterator iter = groupColletionPointer->findGroup(nameOfGroup);
	if (iter == groupColletionPointer->findEnd())
		isExists = false;
	else
		isExists = true;
}



// Function : callCreateGroupUIStartInterface(CreateGroup &createGroup)
// Description: UI�������ϰ�, ��Ʈ���� ref�� �Ѱ��ݴϴ�.
// Parameters : CreateGroup &createGroup
// Return Value : CreateGroupUI*
//
// Created: 2017/5/25 09:08am
// Author: ������
//
CreateGroupUI* CreateGroup::callCreateGroupUIStartInterface(CreateGroup &createGroup)
{
	return CreateGroupUI::startInterface(createGroup);
}