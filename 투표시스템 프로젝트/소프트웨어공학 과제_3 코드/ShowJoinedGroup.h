#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: ShowJoinedGroup
//Description: ShowJoinedGroup 헤더
//created: 2017/5/30 08:04am
//Author: 장현석
//mail: jang8018@naver.com


using namespace std;

class UserCollection;
class GroupCollection;
class ShowJoinedGroupUI;
class User;

class ShowJoinedGroup
{
private:
	UserCollection* userCollectionPointer;
	GroupCollection* groupCollectionPointer;
public:
	ShowJoinedGroupUI* callShowJoinedGroupUIStartInterface(ShowJoinedGroup &showJoinedGroup);
	bool showJoinedGroup(list<User>::iterator loginUser, string &joinedGroupName);

	ShowJoinedGroup();
	//UserCollection &userCollection
	~ShowJoinedGroup();
};

