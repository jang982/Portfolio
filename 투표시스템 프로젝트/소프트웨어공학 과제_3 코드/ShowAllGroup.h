#pragma once

#include <string>
#include <list>


//Class: ShowAllGroup
//Description: ShowAllGroup ���
//created: 2017/5/29 08:17am
//Author: ������
//mail: jang8018@naver.com


using namespace std;

class ShowAllGroupUI;
class GroupCollection;
class UserCollection;
class User;

class ShowAllGroup
{
private:
	GroupCollection* groupColletionPointer;
	UserCollection* userCollectionPointer;

	
public:
	void showAllGroup(string* groupList);
	//void joinGroup(string group_name, list<User>::iterator loginUser);

	ShowAllGroup(GroupCollection &groupCollection);
	~ShowAllGroup();
	ShowAllGroupUI* callShowAllGroupUIStartInterface(ShowAllGroup &showAllGroup);	//�������̽��� �ڱ��ּ�����
	
};

