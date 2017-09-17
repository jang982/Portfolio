#include "Logout.h"
#include "LogoutUI.h"
#include "UserCollection.h"
#include "User.h"

//Function : Logout(UserCollection& userCollection)
//Description : LogoutŬ������ ������
//Parameters : UserCollection& userCollection
//Return Value : none.
//Created : 2017/05/30 3:28 am
//Author : ������

Logout::Logout(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

//Function : void callLoginOnOff(string idOfUser)
//Description : loginOff�Լ��� �ҷ��ִ� �Լ�
//Parameters : string idOfUser
//Return Value : void
//Created : 2017/05/30 3:33 am
//Author : ������
void Logout::callLoginOnOff(string idOfUser)
{
	userCollectionPointer->setLoginOffUser(idOfUser);
}

//Function : ~Logout()
//Description : LogoutŬ������ �ı���
//Parameters : void
//Return Value : none.
//Created : 2017/05/30 3:30 am
//Author : ������
Logout::~Logout()
{
}

//Function : LogoutUI* callLogoutUIStartInterface(Logout& logout)
//Description : �α׾ƿ�UI�� interface�� ��ȯ���ִ� �Լ�
//Parameters : Logout& logout
//Return Value : LogoutUI*
//Created : 2017/05/30 3:40 am
//Author : ������
LogoutUI * Logout::callLogoutUIStartInterface(Logout & logout)
{
	return LogoutUI::startInterface(logout);
}
