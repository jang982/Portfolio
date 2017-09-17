#include "LogoutUI.h"
#include "Logout.h"


//Function :LogoutUI(Logout& logout)
//Description : LogoutUI클래스의 생성자
//Parameters : Logout& logout
//Return Value : none.
//Created : 2017/05/30 3:43 am
//Author : 조현정

LogoutUI::LogoutUI(Logout& logout)
{
	logoutPointer = &logout;
}


//Function :LogoutUI* startInterface(Logout& logout)
//Description : startInterface함수
//Parameters : Logout& logout
//Return Value : LogoutUI
//Created : 2017/05/30 3:46 am
//Author : 조현정
LogoutUI * LogoutUI::startInterface(Logout & logout)
{
	LogoutUI* newPointer = new LogoutUI(logout);
	return newPointer;
}

//Function :void clickLogout(string idOfUser)
//Description : 로그아웃을 클릭(입력)했을 때 호출되는 함수
//Parameters : string idOfUser
//Return Value : void
//Created : 2017/05/30 3:46 am
//Author : 조현정
void LogoutUI::clickLogout(string idOfUser)
{
	logoutPointer->callLoginOnOff(idOfUser);
}

//Function :~LogoutUI()
//Description : LogoutUI클래스의 소멸자
//Parameters : void
//Return Value : none.
//Created : 2017/05/30 3:43 am
//Author : 조현정
LogoutUI::~LogoutUI()
{
}
