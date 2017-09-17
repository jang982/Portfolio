#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: GroupCollection
//Description: GroupCollection 헤더
//created: 2017/5/25 20:25pm
//Author: 장현석
//mail: jang8018@naver.com

using namespace std;

class Group;


class GroupCollection {
private:
	list<Group> GroupList;
	list<Group>::iterator groupListIterator;
public:
	list<Group>::iterator findFirst();
	list<Group>::iterator getNext(list<Group>::iterator &inputIter);
	list<Group>::iterator findEnd();
	list<Group>::iterator findGroup(string nameOfGroup);
	void addGroup(string nameOfGroup);
	void removeGroup(string nameOfGroup);


	GroupCollection();
	~GroupCollection();
};
