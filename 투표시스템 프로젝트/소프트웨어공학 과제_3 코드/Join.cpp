#include "Join.h"
#include "JoinUI.h"
#include"UserCollection.h"
#include"User.h"

// Function : Join(UserCollection& userCollection)
// Description: Join class의 생성자
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 7:5 pm
// Author: 조현정
//
Join::Join(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

// Function : ~Join()
// Description: Join class의 소멸자
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 7:7 pm
// Author: 조현정
//
Join::~Join()
{
}

// Function : bool callCreateUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
// Description: 조건을 체크(중복되는 아이디가 아닌지)하여 조건에 부합한다면 userCollection의 addUser를 호출하는 함수.
// Parameters : string newName, string newPersonalNumber, string newAddress, string newID, string newPwd
// Return Value : bool
//
// Created: 2017/5/29 7:10 pm
// Author: 조현정
//
bool Join::callCreateUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	checkExists(newID);
	if (isExists)
		return 1;
	else {
		userCollectionPointer->addUser(newName, newPersonalNumber,newAddress, newID, newPwd);
		return 0;
	}
}

// Function : checkExists(string idOfUser)
// Description: 중복되는 아이디가 있는지 체크해주는 함수
// Parameters : string idOfUser
// Return Value : void
//
// Created: 2017/5/29 7:15 pm
// Author: 조현정
//
void Join::checkExists(string idOfUser)
{
	list<User>::iterator iter = userCollectionPointer->findUser(idOfUser);
	if (iter == userCollectionPointer->findEnd())
		isExists = false;
	else
		isExists = true;
}

// Function : callJoinUIStartInterface(Join& join)
// Description: JoinUI의 인터페이스를 반환해주는 함수
// Parameters : Join& join
// Return Value : JoinUI*
//
// Created: 2017/5/29 7:18 pm
// Author: 조현정
//
JoinUI* Join::callJoinUIStartInterface(Join& join)
{
	return JoinUI::startInterface(join);
}
