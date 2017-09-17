#include "LeaveGroupUI.h"
#include "LeaveGroup.h"



//Class: LeaveGroupUI
//Description: LeaveGroupUI ����
//created: 2017/5/30 22:10pm
//Author: ������
//mail: jang8018@naver.com


// Function : LeaveGroupUI(LeaveGroup &leaveGroup)
// Description: ��Ʈ���� �ּҸ� �޾� �����͸� �����ϰ� UI�� �����մϴ�.
// Parameters : LeaveGroup &leaveGroup
// Return Value : void
//
// Created: 2017/5/30 22:10pm
// Author: ������
//
LeaveGroupUI::LeaveGroupUI(LeaveGroup &leaveGroup)
{
	leaveGroupPointer = &leaveGroup;
}


LeaveGroupUI::~LeaveGroupUI()
{
}


// Function : confirmLeaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
// Description: ��Ʈ�ѿ� �׷�Ż���Լ� ȣ���� ��û�մϴ�.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 22:14pm
// Author: ������
//
bool LeaveGroupUI::confirmLeaveGroup(list<User>::iterator loginUser, string &joinedGroupName)
{
	return leaveGroupPointer->leaveGroup(loginUser, joinedGroupName);
}

// Function : startInterface(LeaveGroup & leaveGroup)
// Description: ��Ʈ�����޾� UI�����ڸ� ȣ���մϴ�.
// Parameters : LeaveGroup & leaveGroup
// Return Value : LeaveGroupUI *
//
// Created: 2017/5/30 22:17pm
// Author: ������
//
LeaveGroupUI * LeaveGroupUI::startInterface(LeaveGroup & leaveGroup)
{
	LeaveGroupUI* newPointer = new LeaveGroupUI(leaveGroup);
	return newPointer;
}
