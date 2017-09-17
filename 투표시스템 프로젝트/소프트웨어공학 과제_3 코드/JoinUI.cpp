#include "JoinUI.h"
#include "Join.h"

// Function : JoinUI(Join& join)
// Description: JoinUI class�� ������
// Parameters : Join& join
// Return Value : void
//
// Created: 2017/5/29 7:22 pm
// Author: ������
//
JoinUI::JoinUI(Join& join)
{
	joinPointer = &join;
}

// Function : JoinUI()
// Description: JoinUI class�� �Ҹ���
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 7:24 pm
// Author: ������
//
JoinUI::~JoinUI()
{
}

// Function : JoinUI* startInterface(Join& join)
// Description: JoinUI ��ü�� �������ִ� �Լ�.
// Parameters : Join& join
// Return Value : JoinUI*
//
// Created: 2017/5/29 7:26 pm
// Author: ������
//
JoinUI * JoinUI::startInterface(Join& join)
{
	JoinUI* newPointer = new JoinUI(join);
	return newPointer;
}

// Function : bool enterUserInfo(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
// Description: Join Ŭ�������� user���� �Է¹��� ������ �������ְ�, ȸ������ ���� ���θ� ��ȯ�޴´�.
// Parameters : string newName, string newPersonalNumber, string newAddress, string newID, string newPwd
// Return Value : bool
//
// Created: 2017/5/29 7:30 pm
// Author: ������
//
bool JoinUI::enterUserInfo(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	return joinPointer->callCreateUser(newName,newPersonalNumber, newAddress,  newID, newPwd);
}

