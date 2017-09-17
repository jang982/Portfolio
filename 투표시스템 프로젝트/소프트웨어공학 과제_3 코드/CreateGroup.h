#pragma once

#include <iostream>
#include <string>
#include <list>


//Class: CreateGroup
//Description: CreateGroup ���
//created: 2017/5/25 08:57am
//Author: ������
//mail: jang8018@naver.com

using namespace std;

class GroupCollection;
class CreateGroupUI;
class User;


class CreateGroup
{
private:
	GroupCollection*	groupColletionPointer;
	//CreateGroupUI*		createGroupUIPointer;
	bool isExists;

public:
	bool callCreateGroup(string nameOfGroup, list<User>::iterator loginUser);
	void checkExists(string nameOfGroup);

	CreateGroup(GroupCollection &groupCollection);
	~CreateGroup();
	CreateGroupUI* callCreateGroupUIStartInterface(CreateGroup &createGroup);
};

