#pragma once

#include <iostream>
#include <string>
#include <list>


//Class: LeaveGroupUI
//Description: LeaveGroupUI ���
//created: 2017/5/30 22:06pm
//Author: ������
//mail: jang8018@naver.com


using namespace std;

class LeaveGroup;
class User;

class LeaveGroupUI
{
private:
	LeaveGroup* leaveGroupPointer;
public:
	bool confirmLeaveGroup(list<User>::iterator loginUser,string &joinedGroupName);
	static LeaveGroupUI* startInterface(LeaveGroup &leaveGroup);
	LeaveGroupUI(LeaveGroup &leaveGroup);
	~LeaveGroupUI();
};

