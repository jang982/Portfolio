#include "LogoutUI.h"
#include "Logout.h"


//Function :LogoutUI(Logout& logout)
//Description : LogoutUIŬ������ ������
//Parameters : Logout& logout
//Return Value : none.
//Created : 2017/05/30 3:43 am
//Author : ������

LogoutUI::LogoutUI(Logout& logout)
{
	logoutPointer = &logout;
}


//Function :LogoutUI* startInterface(Logout& logout)
//Description : startInterface�Լ�
//Parameters : Logout& logout
//Return Value : LogoutUI
//Created : 2017/05/30 3:46 am
//Author : ������
LogoutUI * LogoutUI::startInterface(Logout & logout)
{
	LogoutUI* newPointer = new LogoutUI(logout);
	return newPointer;
}

//Function :void clickLogout(string idOfUser)
//Description : �α׾ƿ��� Ŭ��(�Է�)���� �� ȣ��Ǵ� �Լ�
//Parameters : string idOfUser
//Return Value : void
//Created : 2017/05/30 3:46 am
//Author : ������
void LogoutUI::clickLogout(string idOfUser)
{
	logoutPointer->callLoginOnOff(idOfUser);
}

//Function :~LogoutUI()
//Description : LogoutUIŬ������ �Ҹ���
//Parameters : void
//Return Value : none.
//Created : 2017/05/30 3:43 am
//Author : ������
LogoutUI::~LogoutUI()
{
}
