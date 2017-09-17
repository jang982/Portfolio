
#include "Group.h"
#include "GroupCollection.h"

//Class: GroupCollection
//Description: GroupCollection ����
//created: 2017/5/25 20:28pm
//Author: ������
//mail: jang8018@naver.com

using namespace std;




GroupCollection::GroupCollection() {}
GroupCollection::~GroupCollection(){}


// Function : findFirst()
// Description: �׷츮��Ʈ�� ù��° �ݺ��ڸ� ��ȯ�մϴ�
// Parameters : none
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:30pm
// Author: ������
//
list<Group>::iterator GroupCollection::findFirst()
{
	groupListIterator = GroupList.begin();
	return groupListIterator;
}


// Function : findEnd()
// Description: �׷츮��Ʈ�� ������ �ݺ��ڸ� ��ȯ�մϴ�
// Parameters : none
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:31pm
// Author: ������
//
list<Group>::iterator GroupCollection::findEnd()
{
	groupListIterator = GroupList.end();
	return groupListIterator;
}


// Function : getNext(list<Group>::iterator &inputIter)
// Description: �׷츮��Ʈ�� �ݺ��ڸ� �������� �Ѱ��ݴϴ�
// Parameters : list<Group>::iterator &inputIter
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:32pm
// Author: ������
//
list<Group>::iterator GroupCollection::getNext(list<Group>::iterator &inputIter)
{
	return inputIter++;
}


// Function : findGroup(string nameOfGroup)
// Description: �׷��̸��� �Է¹޾� �ش�׷���ġ�� �ݺ��ڸ� ��ȯ�մϴ�.
// Parameters : string nameOfGroup
// Return Value : list<Group>::iterator
//
// Created: 2017/5/25 20:40pm
// Author: ������
//
list<Group>::iterator GroupCollection::findGroup(string nameOfGroup)
{
	groupListIterator = GroupList.begin();
	bool success = false;											//��������

	//����Ʈ �˻�
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
// Description: �׷츮��Ʈ�� �׷��� �����ϰ� �߰��մϴ�.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 20:45pm
// Author: ������
//
void GroupCollection::addGroup(string nameOfGroup)
{
	GroupList.push_back(*Group::createGroup(nameOfGroup));
}


// Function : removeGroup(string nameOfGroup)
// Description: �׷��̸��� �Է¹޾� �׷� ����Ʈ���� �׷��� �����մϴ�.
// Parameters : string nameOfGroup
// Return Value : void
//
// Created: 2017/5/25 20:47pm
// Author: ������
//
void GroupCollection::removeGroup(string nameOfGroup)
{
	groupListIterator = GroupList.begin();
	bool find = false;												//��������

	//����Ʈ���� ��������
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

