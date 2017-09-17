#pragma once

#include <iostream>
#include <string>
#include <list>



//Class: ShowAllGroupUI
//Description: ShowAllGroupUI ���
//created: 2017/5/29 09:07am
//Author: ������
//mail: jang8018@naver.com

using namespace std;

class ShowAllGroup;
class User;

class ShowAllGroupUI
{
private:
	ShowAllGroup* showAllGroupPointer;

public:
	void confirmView(string* groupList);
	//void selectGroup(string nameOfGroup, list<User>::iterator loginUser);
	static ShowAllGroupUI* startInterface(ShowAllGroup &showAllGroup);

	ShowAllGroupUI(ShowAllGroup &showAllGroup);
	~ShowAllGroupUI();
};

