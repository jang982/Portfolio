#pragma once

#include <iostream>
#include <string>
#include <list>


//Class: LeaveGroup
//Description: LeaveGroup 헤더
//created: 2017/5/30 21:57pm
//Author: 장현석
//mail: jang8018@naver.com


using namespace std;

class LeaveGroupUI;
class User;

class LeaveGroup
{
private:
	
public:
	LeaveGroupUI*	callJoinGroupUIStartInterface(LeaveGroup &leaveGroup);
	bool			leaveGroup(list<User>::iterator loginUser, string &joinedGroupName);

	LeaveGroup();
	~LeaveGroup();
};

