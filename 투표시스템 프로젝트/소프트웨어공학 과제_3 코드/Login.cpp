#include "Login.h"
#include "LoginUI.h"
#include "UserCollection.h"
#include"User.h"

// Function : Login(UserCollection& userCollection)
// Description: Login class�� ������
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 2:15 am
// Author: ������
//
Login::Login(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

// Function : bool callLoginOnOff(string inputID, string inputPwd, list<User>::iterator allUser)
// Description: ������ üũ(���̵�,��й�ȣ)�Ͽ� ���ǿ� �����Ѵٸ� userCollection�� setLoginUser�� ȣ���ϴ� �Լ�.
// Parameters : string inputID, string inputPwd, list<User>::iterator allUser
// Return Value : bool
//
// Created: 2017/5/29  2:20am
// Author: ������
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
// Description: ���̵�� ��й�ȣ�� ������ ��ġ�ϴ� ��ü�� �ִ��� ã�� �Լ�
// Parameters : string idOfUser
// Return Value : void
//
// Created: 2017/5/29 2:23 am
// Author: ������
//
void Login::checkExists(string inputID, string inputPwd)
{
	list<User>::iterator iter = userCollectionPointer->findUser(inputID);
	if (iter == userCollectionPointer->findEnd())
		isExists = true;
	else {
		//ID ã�� ���
		if (iter->getUserPwd() == inputPwd)
			isExists = false;
		else
			isExists = true;
	}
}

// Function : callJoinUIStartInterface(Login& logoin)
// Description: LoginUI�� �������̽��� ��ȯ���ִ� �Լ�
// Parameters : Login& logoin
// Return Value : LoginUI*
//
// Created: 2017/5/29 2:30 am
// Author: ������
//
LoginUI * Login::callLoginUIStartInterface(Login & login)
{
	return LoginUI::startInterface(login);
}

// Function : ~Login()
// Description: Login class�� �Ҹ���
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 2:15 am
// Author: ������
//
Login::~Login()
{
}
