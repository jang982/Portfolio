#include "Login.h"
#include "LoginUI.h"
#include "UserCollection.h"
#include"User.h"

// Function : Login(UserCollection& userCollection)
// Description: Login class의 생성자
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 2:15 am
// Author: 조현정
//
Login::Login(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

// Function : bool callLoginOnOff(string inputID, string inputPwd, list<User>::iterator allUser)
// Description: 조건을 체크(아이디,비밀번호)하여 조건에 부합한다면 userCollection의 setLoginUser를 호출하는 함수.
// Parameters : string inputID, string inputPwd, list<User>::iterator allUser
// Return Value : bool
//
// Created: 2017/5/29  2:20am
// Author: 조현정
//
bool Login::callLoginOnOff(string inputID, string inputPwd, list<User>::iterator allUser)
{
	checkExists(inputID, inputPwd);
	if (isExists)
		return 1;
	else {
		userCollectionPointer->setLoginUser(inputID);
		return 0;
	}
}

// Function : checkExists(string idOfUser)
// Description: 아이디와 비밀번호의 정보가 일치하는 객체가 있는지 찾는 함수
// Parameters : string idOfUser
// Return Value : void
//
// Created: 2017/5/29 2:23 am
// Author: 조현정
//
void Login::checkExists(string inputID, string inputPwd)
{
	list<User>::iterator iter = userCollectionPointer->findUser(inputID);
	if (iter == userCollectionPointer->findEnd())
		isExists = true;
	else {
		//ID 찾은 경우
		if (iter->getUserPwd() == inputPwd)
			isExists = false;
		else
			isExists = true;
	}
}

// Function : callJoinUIStartInterface(Login& logoin)
// Description: LoginUI의 인터페이스를 반환해주는 함수
// Parameters : Login& logoin
// Return Value : LoginUI*
//
// Created: 2017/5/29 2:30 am
// Author: 조현정
//
LoginUI * Login::callLoginUIStartInterface(Login & login)
{
	return LoginUI::startInterface(login);
}

// Function : ~Login()
// Description: Login class의 소멸자
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 2:15 am
// Author: 조현정
//
Login::~Login()
{
}
