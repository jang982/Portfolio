#include "CreateGroup.h"
#include "CreateGroupUI.h"


//Class: CreateGroupUI
//Description: CreateGroupUI 구현
//created: 2017/5/25 09:15am
//Author: 장현석
//mail: jang8018@naver.com



// Function : CreateGroupUI(CreateGroup &createGroup)
// Description: 그룹생성 컨트롤주소를받아 포인터를 할당하고, UI를 생성합니다.
// Parameters : CreateGroup &createGroup
// Return Value : void
//
// Created: 2017/5/25 09:20am
// Author: 장현석
//
CreateGroupUI::CreateGroupUI(CreateGroup &createGroup)
{
	createGroupPointer = &createGroup;
}


CreateGroupUI::~CreateGroupUI()
{
}



// Function : startInterface(CreateGroup &creatGroup)
// Description: 컨트롤을 받아 CreateUI클래스의 인터페이스를 생성합니다.
// Parameters : CreateGroup &creatGroup
// Return Value : CreateGroupUI*
//
// Created: 2017/5/25 09:20am
// Author: 장현석
//
CreateGroupUI* CreateGroupUI::startInterface(CreateGroup &creatGroup)
{
	CreateGroupUI* newPointer = new CreateGroupUI(creatGroup);
	return newPointer;
}


// Function : setGroupName(string nameOfGroup, list<User>::iterator loginUser)
// Description: 유저의 반복자와 그룹이름명을 받아 callCreateGroup을 불러줍니다.
// Parameters : CreateGroup &creatGroup
// Return Value : string nameOfGroup, list<User>::iterator loginUser
//
// Created: 2017/5/25 09:25am
// Author: 장현석
//
bool CreateGroupUI::setGroupName(string nameOfGroup, list<User>::iterator loginUser)
{
	return createGroupPointer->callCreateGroup(nameOfGroup, loginUser);
}