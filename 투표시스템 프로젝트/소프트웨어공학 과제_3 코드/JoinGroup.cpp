#include "JoinGroup.h"
#include "JoinGroupUI.h"
#include "UserCollection.h"
#include "GroupCollection.h"
#include "User.h"
#include "Group.h"

//Class: JoinGroup
//Description: JoinGroup 구현
//created: 2017/5/26 21:10pm
//Author: 장현석
//mail: jang8018@naver.com


// Function : JoinGroup(GroupCollection &groupCollection, UserCollection &userCollection)
// Description: 그룹콜렉션과 유저콜렉션주소를 받아 포인터를 지정하고, 컨트롤을 생성합니다.
// Parameters : GroupCollection &groupCollection, UserCollection &userCollection
// Return Value : void
//
// Created: 2017/5/26 21:10pm
// Author: 장현석
//
JoinGroup::JoinGroup(GroupCollection &groupCollection, UserCollection &userCollection)
{
	groupCollectionPointer = &groupCollection;
	userCollectionPointer = &userCollection;
}


JoinGroup::~JoinGroup()
{
}

// Function : callJoinGroupUIStartInterface(JoinGroup & joinGroup)
// Description: 그룹가입 컨트롤을 받아와서 UI생성을 콜합니다.
// Parameters : JoinGroup & joinGroup
// Return Value : JoinGroupUI *
//
// Created: 2017/5/26 21:12pm
// Author: 장현석
//
JoinGroupUI * JoinGroup::callJoinGroupUIStartInterface(JoinGroup & joinGroup)
{
	return JoinGroupUI::startInterface(joinGroup);
}


// Function : joinGroup(string group_name, list<User>::iterator loginUser)
// Description: 로그인중인 유저의 반복자와 그룹이름을 받아와 그룹에 가입시킵니다.
// Parameters : string group_name, list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/26 21:13pm
// Author: 장현석
//
bool JoinGroup::joinGroup(string group_name, list<User>::iterator loginUser)
{
	list<Group>::iterator iter = groupCollectionPointer->findGroup(group_name);

	if (iter == groupCollectionPointer->findEnd())
	{
		return true;
	}
	else
	{
		loginUser->setJoinedGroup(group_name);
		return false;
	}
	
}
