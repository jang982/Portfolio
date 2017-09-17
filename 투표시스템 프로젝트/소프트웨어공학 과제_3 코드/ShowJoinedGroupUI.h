#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: ShowJoinedGroupUI
//Description: ShowJoinedGroupUI ���
//created: 2017/5/30 08:29am
//Author: ������
//mail: jang8018@naver.com


using namespace std;

class ShowJoinedGroup;
class User;

class ShowJoinedGroupUI
{
private:
	ShowJoinedGroup* showJoinedGroupPointer;
public:
	bool confirmView(list<User>::iterator loginUser,string &joinedGroupName);
	static ShowJoinedGroupUI* startInterface(ShowJoinedGroup &showJoinedGroup);

	ShowJoinedGroupUI(ShowJoinedGroup &showJoinedGroup);
	~ShowJoinedGroupUI();
};

