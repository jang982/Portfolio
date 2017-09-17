#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: Group
//Description: Group ��� �ۼ�
//created: 2017/5/25 19:50pm
//Author: ������
//mail: jang8018@naver.com


using namespace std;

class Group;
class UserCollection;



class Group {
private:
	string			groupName;
public:
	Group(string nameOfGroup);
	~Group();

	static Group*	createGroup(string nameOfGroup);
	void			deleteGroup();

	string			getGroupName();
	void			setGroupName(string inputName);
};