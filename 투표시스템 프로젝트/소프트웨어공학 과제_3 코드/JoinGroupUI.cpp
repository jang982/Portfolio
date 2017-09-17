#include "JoinGroupUI.h"
#include "JoinGroup.h"



//Class: JoinGroupUI
//Description: JoinGroupUI ����
//created: 2017/5/26 21:30pm
//Author: ������
//mail: jang8018@naver.com


// Function : JoinGroupUI(JoinGroup &joinGroup)
// Description: �׷찡�� ��Ʈ���� �ּҸ� �޾� �����͸� �����ϰ�, UI�� �����մϴ�.
// Parameters : JoinGroup &joinGroup
// Return Value : void
//
// Created: 2017/5/26 21:30pm
// Author: ������
//
JoinGroupUI::JoinGroupUI(JoinGroup &joinGroup)
{
	joinGroupPointer = &joinGroup;
}


JoinGroupUI::~JoinGroupUI()
{
}


// Function : selectGroup(string nameOfGroup, list<User>::iterator loginUser)
// Description: ������ �׷��� �̸��� �Է¹޾� ��Ʈ���� �׷찡���� ���մϴ�.
// Parameters : string nameOfGroup, list<User>::iterator loginUser
// Return Value : bool
//
// Created: 2017/5/26 21:31pm
// Author: ������
//
bool JoinGroupUI::selectGroup(string nameOfGroup, list<User>::iterator loginUser)
{
	return joinGroupPointer->joinGroup(nameOfGroup, loginUser);
}

// Function : startInterface(JoinGroup & joinGroup)
// Description: ��Ʈ���ּҸ� �޾� UI�� �������̽��� �����ϰ� �ش� �ּҰ��� ��ȯ�մϴ�.
// Parameters : JoinGroup & joinGroup
// Return Value : JoinGroupUI *
//
// Created: 2017/5/26 21:35pm
// Author: ������
//
JoinGroupUI * JoinGroupUI::startInterface(JoinGroup & joinGroup)
{
	JoinGroupUI* newPointer = new JoinGroupUI(joinGroup);
	return newPointer;
}
