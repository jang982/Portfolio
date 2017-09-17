#include "Logout.h"
#include "LogoutUI.h"
#include "UserCollection.h"
#include "User.h"

//Function : Logout(UserCollection& userCollection)
//Description : Logout클래스의 생성자
//Parameters : UserCollection& userCollection
//Return Value : none.
//Created : 2017/05/30 3:28 am
//Author : 조현정

Logout::Logout(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

//Function : void callLoginOnOff(string idOfUser)
//Description : loginOff함수를 불러주는 함수
//Parameters : string idOfUser
//Return Value : void
//Created : 2017/05/30 3:33 am
//Author : 조현정
void Logout::callLoginOnOff(string idOfUser)
{
	userCollectionPointer->setLoginOffUser(idOfUser);
}

//Function : ~Logout()
//Description : Logout클래스의 파괴자
//Parameters : void
//Return Value : none.
//Created : 2017/05/30 3:30 am
//Author : 조현정
Logout::~Logout()
{
}

//Function : LogoutUI* callLogoutUIStartInterface(Logout& logout)
//Description : 로그아웃UI의 interface를 반환해주는 함수
//Parameters : Logout& logout
//Return Value : LogoutUI*
//Created : 2017/05/30 3:40 am
//Author : 조현정
LogoutUI * Logout::callLogoutUIStartInterface(Logout & logout)
{
	return LogoutUI::startInterface(logout);
}
