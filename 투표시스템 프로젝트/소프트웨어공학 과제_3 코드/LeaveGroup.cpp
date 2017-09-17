#include "LeaveGroup.h"
#include "LeaveGroupUI.h"
#include "User.h"



//Class: LeaveGroup
//Description: LeaveGroup 구현
//created: 2017/5/30 22:00pm
//Author: 장현석
//mail: jang8018@naver.com



LeaveGroup::LeaveGroup()
{
}


LeaveGroup::~LeaveGroup()
{
}

// Function : callJoinGroupUIStartInterface(LeaveGroup & leaveGroup)
// Description: 컨트롤의 주소를 전달하여 그룹탈퇴UI 인터페이스를 호출합니다.
// Parameters : LeaveGroup & leaveGroup
// Return Value : LeaveGroupUI *
//
// Created: 2017/5/30 22:00pm
// Author: 장현석
//
LeaveGroupUI * LeaveGroup::callJoinGroupUIStartInterface(LeaveGroup & leaveGroup)
{
	return LeaveGroupUI::startInterface(leaveGroup);
}


// Function : leaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
// Description: 로그인한 유저가 속한 그룹을 탈퇴합니다.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 22:03pm
// Author: 장현석
//
bool LeaveGroup::leaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
{
	if (loginUser->getIsLeader())
	{
		return true;
	}
	else
	{

		joinedGroupName = loginUser->getJoinedGroup();
		loginUser->withdrawGroup();
		return false;
	}

}
