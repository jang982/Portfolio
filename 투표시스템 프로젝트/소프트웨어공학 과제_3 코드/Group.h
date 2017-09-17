#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: Group
//Description: Group 헤더 작성
//created: 2017/5/25 19:50pm
//Author: 장현석
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