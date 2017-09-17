#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: CreateGroupUI
//Description: CreateGroupUI ���
//created: 2017/5/25 09:10am
//Author: ������
//mail: jang8018@naver.com


using namespace std;

class CreateGroup;
class User;

class CreateGroupUI
{
private:
	CreateGroup* createGroupPointer;

public:
	static CreateGroupUI* startInterface(CreateGroup &creatGroup);
	bool setGroupName(string nameOfGroup, list<User>::iterator loginUser);

	CreateGroupUI(CreateGroup &createGroup);
	~CreateGroupUI();
	
};

