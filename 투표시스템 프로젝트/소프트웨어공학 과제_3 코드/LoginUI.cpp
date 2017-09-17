#include "LoginUI.h"
#include "Login.h"


// Function : LoginUI* startInterface(Login & login)
// Description: LoginUI ��ü�� �������ִ� �Լ�.
// Parameters : Login& login
// Return Value : LoginUI*
//
// Created: 2017/5/29 2:45 am
// Author: ������
//
LoginUI * LoginUI::startInterface(Login & login)
{
	LoginUI* newPointer = new LoginUI(login);
	return newPointer;
}

// Function : bool getUserInfo(string inputID, string inputPwd, list<User>::iterator allUser)
// Description: Login Ŭ�������� user���� �Է¹��� ������ �������ְ�, �α��� ���� ���θ� ��ȯ�޴´�.
// Parameters : inputID, string inputPwd, list<User>::iterator allUser
// Return Value : bool
//
// Created: 2017/5/29 2:54 am
// Author: ������
//
bool LoginUI::getUserInfo(string inputID, string inputPwd, list<User>::iterator allUser)
{
	return loginPointer->callLoginOnOff(inputID, inputPwd, allUser);
}

// Function : LoginUI(Login& logoin)
// Description: LoginUIŬ������ ������
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 2:40 am
// Author: ������
LoginUI::LoginUI(Login& login)
{
	loginPointer = &login;
}

// Function : ~LoginUI()
// Description: LoginUIŬ������ �Ҹ���
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 2:42 am
// Author: ������
LoginUI::~LoginUI()
{
}
