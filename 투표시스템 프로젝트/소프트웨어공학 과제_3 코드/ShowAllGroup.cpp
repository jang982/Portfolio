#include "ShowAllGroup.h"
#include "ShowAllGroupUI.h"
#include "Group.h"
#include "User.h"
#include "UserCollection.h"
#include "GroupCollection.h"



//Class: ShowAllGroup
//Description: ShowAllGroup 구현
//created: 2017/5/29 08:20am
//Author: 장현석
//mail: jang8018@naver.com


// Function : ShowAllGroup(GroupCollection &groupCollection)
// Description: 그룹콜렉션주소를 받아 컨트롤을 생성합니다.
// Parameters : GroupCollection &groupCollection
// Return Value : void
//
// Created: 2017/5/29 08:20am
// Author: 장현석
//
ShowAllGroup::ShowAllGroup(GroupCollection &groupCollection)
{
	groupColletionPointer = &groupCollection;
}


ShowAllGroup::~ShowAllGroup()
{
}


// Function : showAllGroup(string* groupList)
// Description: 문자열 배열을 받아 그룹리스트에서 그룹명을받아 저장합니다.
// Parameters : string* groupList
// Return Value : void
//
// Created: 2017/5/29 08:25am
// Author: 장현석
//
void ShowAllGroup::showAllGroup(string* groupList)
{
	list<Group>::iterator iter = groupColletionPointer->findFirst();
	list<Group>::iterator iterEnd = groupColletionPointer->findEnd();

	int i = 0;
	while (iter != iterEnd)
	{
		groupList[i++]=iter->getGroupName();
		groupColletionPointer->getNext(iter);
	}


}


// Function : callShowAllGroupUIStartInterface(ShowAllGroup &showAllGroup)
// Description: UI의 인터페이스를 호출합니다.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : ShowAllGroupUI*
//
// Created: 2017/5/29 08:30am
// Author: 장현석
//
ShowAllGroupUI* ShowAllGroup::callShowAllGroupUIStartInterface(ShowAllGroup &showAllGroup)
{
	return ShowAllGroupUI::startInterface(showAllGroup);
}
