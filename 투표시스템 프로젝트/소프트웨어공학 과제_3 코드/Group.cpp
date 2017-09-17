#include "Group.h"
#include "GroupCollection.h"

//Class: Group
//Description: Group ����
//created: 2017/5/25 20:00pm
//Author: ������
//mail: jang8018@naver.com



// Function : Group(string nameOfGroup)
// Description: �׷��̸��� �޾� �׷��� ����ϴ�.
// Parameters : CreateGroup &creatGroup
// Return Value : void
//
// Created: 2017/5/25 20:01pm
// Author: ������
//
Group::Group(string nameOfGroup)
{
	groupName = nameOfGroup;
}

Group::~Group()
{

}

// Function : createGroup(string nameOfGroup)
// Description: �׷��̸��� �޾� �����ڸ� ȣ���� ��, �����͸� ��ȯ�մϴ�.
// Parameters : string nameOfGroup
// Return Value : Group*
//
// Created: 2017/5/25 20:05pm
// Author: ������
//
Group* Group::createGroup(string nameOfGroup)
{
	Group* newGroup = new Group(nameOfGroup);
	return newGroup;
}


// Function : deleteGroup()
// Description: �׷��� �����մϴ�.
// Parameters : none
// Return Value : void
//
// Created: 2017/5/25 20:06pm
// Author: ������
//
void Group::deleteGroup()
{
	Group::~Group();
}


// Function : getGroupName() 
// Description: �׷��̸��� �޾ƿɴϴ�.
// Parameters : none
// Return Value : string
//
// Created: 2017/5/25 20:08pm
// Author: ������
//
string Group::getGroupName() 
{
	return groupName;
}



// Function : setGroupName(string inputName)
// Description: �׷��̸��� �ٲߴϴ�.
// Parameters : string inputName
// Return Value : void
//
// Created: 2017/5/25 20:10pm
// Author: ������
//
void Group::setGroupName(string inputName)
{
	groupName = inputName;
}