#include "CreateGroup.h"
#include "CreateGroupUI.h"


//Class: CreateGroupUI
//Description: CreateGroupUI ����
//created: 2017/5/25 09:15am
//Author: ������
//mail: jang8018@naver.com



// Function : CreateGroupUI(CreateGroup &createGroup)
// Description: �׷���� ��Ʈ���ּҸ��޾� �����͸� �Ҵ��ϰ�, UI�� �����մϴ�.
// Parameters : CreateGroup &createGroup
// Return Value : void
//
// Created: 2017/5/25 09:20am
// Author: ������
//
CreateGroupUI::CreateGroupUI(CreateGroup &createGroup)
{
	createGroupPointer = &createGroup;
}


CreateGroupUI::~CreateGroupUI()
{
}



// Function : startInterface(CreateGroup &creatGroup)
// Description: ��Ʈ���� �޾� CreateUIŬ������ �������̽��� �����մϴ�.
// Parameters : CreateGroup &creatGroup
// Return Value : CreateGroupUI*
//
// Created: 2017/5/25 09:20am
// Author: ������
//
CreateGroupUI* CreateGroupUI::startInterface(CreateGroup &creatGroup)
{
	CreateGroupUI* newPointer = new CreateGroupUI(creatGroup);
	return newPointer;
}


// Function : setGroupName(string nameOfGroup, list<User>::iterator loginUser)
// Description: ������ �ݺ��ڿ� �׷��̸����� �޾� callCreateGroup�� �ҷ��ݴϴ�.
// Parameters : CreateGroup &creatGroup
// Return Value : string nameOfGroup, list<User>::iterator loginUser
//
// Created: 2017/5/25 09:25am
// Author: ������
//
bool CreateGroupUI::setGroupName(string nameOfGroup, list<User>::iterator loginUser)
{
	return createGroupPointer->callCreateGroup(nameOfGroup, loginUser);
}