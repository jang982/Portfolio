#include "JoinUI.h"
#include "Join.h"

// Function : JoinUI(Join& join)
// Description: JoinUI class의 생성자
// Parameters : Join& join
// Return Value : void
//
// Created: 2017/5/29 7:22 pm
// Author: 조현정
//
JoinUI::JoinUI(Join& join)
{
	joinPointer = &join;
}

// Function : JoinUI()
// Description: JoinUI class의 소멸자
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 7:24 pm
// Author: 조현정
//
JoinUI::~JoinUI()
{
}

// Function : JoinUI* startInterface(Join& join)
// Description: JoinUI 객체를 생성해주는 함수.
// Parameters : Join& join
// Return Value : JoinUI*
//
// Created: 2017/5/29 7:26 pm
// Author: 조현정
//
JoinUI * JoinUI::startInterface(Join& join)
{
	JoinUI* newPointer = new JoinUI(join);
	return newPointer;
}

// Function : bool enterUserInfo(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
// Description: Join 클래스에게 user에게 입력받은 정보를 전달해주고, 회원가입 성공 여부를 반환받는다.
// Parameters : string newName, string newPersonalNumber, string newAddress, string newID, string newPwd
// Return Value : bool
//
// Created: 2017/5/29 7:30 pm
// Author: 조현정
//
bool JoinUI::enterUserInfo(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	return joinPointer->callCreateUser(newName,newPersonalNumber, newAddress,  newID, newPwd);
}

