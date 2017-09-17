#include "JoinGroupUI.h"
#include "JoinGroup.h"



//Class: JoinGroupUI
//Description: JoinGroupUI 구현
//created: 2017/5/26 21:30pm
//Author: 장현석
//mail: jang8018@naver.com


// Function : JoinGroupUI(JoinGroup &joinGroup)
// Description: 그룹가입 컨트롤의 주소를 받아 포인터를 지정하고, UI를 생성합니다.
// Parameters : JoinGroup &joinGroup
// Return Value : void
//
// Created: 2017/5/26 21:30pm
// Author: 장현석
//
JoinGroupUI::JoinGroupUI(JoinGroup &joinGroup)
{
	joinGroupPointer = &joinGroup;
}


JoinGroupUI::~JoinGroupUI()
{
}


// Function : selectGroup(string nameOfGroup, list<User>::iterator loginUser)
// Description: 선택한 그룹의 이름을 입력받아 컨트롤의 그룹가입을 콜합니다.
// Parameters : string nameOfGroup, list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/26 21:31pm
// Author: 장현석
//
bool JoinGroupUI::selectGroup(string nameOfGroup, list<User>::iterator loginUser)
{
	return joinGroupPointer->joinGroup(nameOfGroup, loginUser);
}

// Function : startInterface(JoinGroup & joinGroup)
// Description: 컨트롤주소를 받아 UI의 인터페이스를 생성하고 해당 주소값을 반환합니다.
// Parameters : JoinGroup & joinGroup
// Return Value : JoinGroupUI *
//
// Created: 2017/5/26 21:35pm
// Author: 장현석
//
JoinGroupUI * JoinGroupUI::startInterface(JoinGroup & joinGroup)
{
	JoinGroupUI* newPointer = new JoinGroupUI(joinGroup);
	return newPointer;
}
