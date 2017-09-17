#include "LeaveGroup.h"
#include "LeaveGroupUI.h"
#include "User.h"



//Class: LeaveGroup
//Description: LeaveGroup ����
//created: 2017/5/30 22:00pm
//Author: ������
//mail: jang8018@naver.com



LeaveGroup::LeaveGroup()
{
}


LeaveGroup::~LeaveGroup()
{
}

// Function : callJoinGroupUIStartInterface(LeaveGroup & leaveGroup)
// Description: ��Ʈ���� �ּҸ� �����Ͽ� �׷�Ż��UI �������̽��� ȣ���մϴ�.
// Parameters : LeaveGroup & leaveGroup
// Return Value : LeaveGroupUI *
//
// Created: 2017/5/30 22:00pm
// Author: ������
//
LeaveGroupUI * LeaveGroup::callJoinGroupUIStartInterface(LeaveGroup & leaveGroup)
{
	return LeaveGroupUI::startInterface(leaveGroup);
}


// Function : leaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
// Description: �α����� ������ ���� �׷��� Ż���մϴ�.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 22:03pm
// Author: ������
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
