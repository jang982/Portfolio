#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: JoinGroup
//Description: JoinGroup 헤더
//created: 2017/5/26 21:08pm
//Author: 장현석
//mail: jang8018@naver.com

using namespace std;

class UserCollection;
class GroupCollection;
class JoinGroupUI;
class User;

class JoinGroup
{
private:
	UserCollection* userCollectionPointer;
	GroupCollection* groupCollectionPointer;
public:
	JoinGroupUI* callJoinGroupUIStartInterface(JoinGroup &joinGroup);
	bool joinGroup(string group_name, list<User>::iterator loginUser);

	JoinGroup(GroupCollection &groupCollection,UserCollection &userCollection);
	~JoinGroup();
};

