#include "Group.h"
#include "GroupCollection.h"

//Class: Group
//Description: Group 구현
//created: 2017/5/25 20:00pm
//Author: 장현석
//mail: jang8018@naver.com



// Function : Group(string nameOfGroup)
// Description: 그룹이름을 받아 그룹을 만듭니다.
// Parameters : CreateGroup &creatGroup
// Return Value : void
//
// Created: 2017/5/25 20:01pm
// Author: 장현석
//
Group::Group(string nameOfGroup)
{
	groupName = nameOfGroup;
}

Group::~Group()
{

}

// Function : createGroup(string nameOfGroup)
// Description: 그룹이름을 받아 생성자를 호출한 후, 포인터를 반환합니다.
// Parameters : string nameOfGroup
// Return Value : Group*
//
// Created: 2017/5/25 20:05pm
// Author: 장현석
//
Group* Group::createGroup(string nameOfGroup)
{
	Group* newGroup = new Group(nameOfGroup);
	return newGroup;
}


// Function : deleteGroup()
// Description: 그룹을 삭제합니다.
// Parameters : none
// Return Value : void
//
// Created: 2017/5/25 20:06pm
// Author: 장현석
//
void Group::deleteGroup()
{
	Group::~Group();
}


// Function : getGroupName() 
// Description: 그룹이름을 받아옵니다.
// Parameters : none
// Return Value : string
//
// Created: 2017/5/25 20:08pm
// Author: 장현석
//
string Group::getGroupName() 
{
	return groupName;
}



// Function : setGroupName(string inputName)
// Description: 그룹이름을 바꿉니다.
// Parameters : string inputName
// Return Value : void
//
// Created: 2017/5/25 20:10pm
// Author: 장현석
//
void Group::setGroupName(string inputName)
{
	groupName = inputName;
}