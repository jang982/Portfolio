#include "LoginUI.h"
#include "Login.h"


// Function : LoginUI* startInterface(Login & login)
// Description: LoginUI 객체를 생성해주는 함수.
// Parameters : Login& login
// Return Value : LoginUI*
//
// Created: 2017/5/29 2:45 am
// Author: 조현정
//
LoginUI * LoginUI::startInterface(Login & login)
{
	LoginUI* newPointer = new LoginUI(login);
	return newPointer;
}

// Function : bool getUserInfo(string inputID, string inputPwd, list<User>::iterator allUser)
// Description: Login 클래스에게 user에게 입력받은 정보를 전달해주고, 로그인 성공 여부를 반환받는다.
// Parameters : inputID, string inputPwd, list<User>::iterator allUser
// Return Value : bool
//
// Created: 2017/5/29 2:54 am
// Author: 조현정
//
bool LoginUI::getUserInfo(string inputID, string inputPwd, list<User>::iterator allUser)
{
	return loginPointer->callLoginOnOff(inputID, inputPwd, allUser);
}

// Function : LoginUI(Login& logoin)
// Description: LoginUI클래스의 생성자
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 2:40 am
// Author: 조현정
LoginUI::LoginUI(Login& login)
{
	loginPointer = &login;
}

// Function : ~LoginUI()
// Description: LoginUI클래스의 소멸자
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 2:42 am
// Author: 조현정
LoginUI::~LoginUI()
{
}
