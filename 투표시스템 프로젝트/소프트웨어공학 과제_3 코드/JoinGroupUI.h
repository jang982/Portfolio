#pragma once

#include <iostream>
#include <string>
#include <list>



//Class: JoinGroupUI
//Description: JoinGroupUI ���
//created: 2017/5/26 21:28pm
//Author: ������
//mail: jang8018@naver.com

using namespace std;

class JoinGroup;
class User;

class JoinGroupUI
{
private:
	JoinGroup* joinGroupPointer;
public:


	bool selectGroup(string nameOfGroup, list<User>::iterator loginUser);
	static JoinGroupUI* startInterface(JoinGroup &joinGroup);

	JoinGroupUI(JoinGroup &joinGroup);
	~JoinGroupUI();
};

