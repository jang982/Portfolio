#include "LeaveGroupUI.h"
#include "LeaveGroup.h"



//Class: LeaveGroupUI
//Description: LeaveGroupUI 구현
//created: 2017/5/30 22:10pm
//Author: 장현석
//mail: jang8018@naver.com


// Function : LeaveGroupUI(LeaveGroup &leaveGroup)
// Description: 컨트롤의 주소를 받아 포인터를 지정하고 UI를 생성합니다.
// Parameters : LeaveGroup &leaveGroup
// Return Value : void
//
// Created: 2017/5/30 22:10pm
// Author: 장현석
//
LeaveGroupUI::LeaveGroupUI(LeaveGroup &leaveGroup)
{
	leaveGroupPointer = &leaveGroup;
}


LeaveGroupUI::~LeaveGroupUI()
{
}


// Function : confirmLeaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
// Description: 컨트롤에 그룹탈퇴함수 호출을 요청합니다.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 22:14pm
// Author: 장현석
//
bool LeaveGroupUI::confirmLeaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
{
	return leaveGroupPointer->leaveGroup(loginUser, joinedGroupName);
}

// Function : startInterface(LeaveGroup & leaveGroup)
// Description: 컨트롤을받아 UI생성자를 호출합니다.
// Parameters : LeaveGroup & leaveGroup
// Return Value : LeaveGroupUI *
//
// Created: 2017/5/30 22:17pm
// Author: 장현석
//
LeaveGroupUI * LeaveGroupUI::startInterface(LeaveGroup & leaveGroup)
{
	LeaveGroupUI* newPointer = new LeaveGroupUI(leaveGroup);
	return newPointer;
}
