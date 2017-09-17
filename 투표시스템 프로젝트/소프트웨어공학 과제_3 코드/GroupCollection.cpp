
#include "Group.h"
#include "GroupCollection.h"

//Class: GroupCollection
//Description: GroupCollection 구현
//created: 2017/5/25 20:28pm
//Author: 장현석
//mail: jang8018@naver.com

using namespace std;




GroupCollection::GroupCollection() {}
GroupCollection::~GroupCollection(){}


// Function : findFirst()
// Description: 그룹리스트의 첫번째 반복자를 반환합니다
// Parameters : none
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:30pm
// Author: 장현석
//
list<Group>::iterator GroupCollection::findFirst()
{
	groupListIterator = GroupList.begin();
	return groupListIterator;
}


// Function : findEnd()
// Description: 그룹리스트의 마지막 반복자를 반환합니다
// Parameters : none
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:31pm
// Author: 장현석
//
list<Group>::iterator GroupCollection::findEnd()
{
	groupListIterator = GroupList.end();
	return groupListIterator;
}


// Function : getNext(list<Group>::iterator &inputIter)
// Description: 그룹리스트의 반복자를 다음으로 넘겨줍니다
// Parameters : list<Group>::iterator &inputIter
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:32pm
// Author: 장현석
//
list<Group>::iterator GroupCollection::getNext(list<Group>::iterator &inputIter)
{
	return inputIter++;
}


// Function : findGroup(string nameOfGroup)
// Description: 그룹이름을 입력받아 해당그룹위치의 반복자를 반환합니다.
// Parameters : string nameOfGroup
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:40pm
// Author: 장현석
//
list<Group>::iterator GroupCollection::findGroup(string nameOfGroup)
{
	groupListIterator = GroupList.begin();
	bool success = false;											//성공여부

	//리스트 검색
	for (groupListIterator = GroupList.begin(); groupListIterator != GroupList.end(); groupListIterator++)
	{
		if (groupListIterator->getGroupName() == nameOfGroup)
		{
			success = true;
			break;
		}
	}

	

	return groupListIterator;
}




// Function : addGroup(string nameOfGroup)
// Description: 그룹리스트에 그룹을 생성하고 추가합니다.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 20:45pm
// Author: 장현석
//
void GroupCollection::addGroup(string nameOfGroup)
{
	GroupList.push_back(*Group::createGroup(nameOfGroup));
}


// Function : removeGroup(string nameOfGroup)
// Description: 그룹이름을 입력받아 그룹 리스트에서 그룹을 삭제합니다.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 20:47pm
// Author: 장현석
//
void GroupCollection::removeGroup(string nameOfGroup)
{
	groupListIterator = GroupList.begin();
	bool find = false;												//성공여부

	//리스트에서 삭제과정
	for (groupListIterator = GroupList.begin(); groupListIterator != GroupList.end(); groupListIterator++)
	{
		if (groupListIterator->getGroupName() == nameOfGroup)
		{
			groupListIterator->deleteGroup();
			groupListIterator = GroupList.erase(groupListIterator);
			find = true;
			break;
		}
		
	}

	

	groupListIterator = GroupList.begin();
}

