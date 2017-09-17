#include "GroupCollection.h"
#include "CreateGroup.h"
#include "CreateGroupUI.h"
#include "Group.h"
#include "User.h"


//Class: CreateGroup
//Description: CreateGroup 구현
//created: 2017/5/25 09:00am
//Author: 장현석
//mail: jang8018@naver.com




// Function : CreateGroup(GroupCollection &groupCollection)
// Description: 그룹 콜렉션주소를 포인터에 할당합니다
// Parameters : GroupCollection &groupCollection
// Return Value : void
//
// Created: 2017/5/25 09:03am
// Author: 장현석
//
CreateGroup::CreateGroup(GroupCollection &groupCollection)
{
	groupColletionPointer = &groupCollection;
}


CreateGroup::~CreateGroup()
{
}


// Function : callCreateGroup(string nameOfGroup, list<User>::iterator loginUser)
// Description: 그룹 이름을 받아서 중복을 체크하고, 생성합니다. 중복이면 에러값을 반환합니다.
// Parameters : string nameOfGroup
//				list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/25 09:04am
// Author: 장현석
//
bool CreateGroup::callCreateGroup(string nameOfGroup, list<User>::iterator loginUser)
{
	if (loginUser->getJoinedGroup() == "none")
	{
		checkExists(nameOfGroup);
		if (isExists)
		{
			return 1;
		}
		else
		{
			groupColletionPointer->addGroup(nameOfGroup);
			loginUser->setGroupLeader();
			loginUser->setJoinedGroup(nameOfGroup);
			return 0;
		}
	}
	else
		return 1;
	
}



// Function : checkExists(string nameOfGroup)
// Description: 반복자를 받아와서 중복인지 판단합니다.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 09:10am
// Author: 장현석
//
void CreateGroup::checkExists(string nameOfGroup)
{
	list<Group>::iterator iter = groupColletionPointer->findGroup(nameOfGroup);
	if (iter == groupColletionPointer->findEnd())
		isExists = false;
	else
		isExists = true;
}



// Function : callCreateGroupUIStartInterface(CreateGroup &createGroup)
// Description: UI생성을하고, 컨트롤의 ref를 넘겨줍니다.
// Parameters : CreateGroup &createGroup
// Return Value : CreateGroupUI*
//
// Created: 2017/5/25 09:08am
// Author: 장현석
//
CreateGroupUI* CreateGroup::callCreateGroupUIStartInterface(CreateGroup &createGroup)
{
	return CreateGroupUI::startInterface(createGroup);
}