#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class UserCollection;
class LogoutUI;
class User;


//class : Logout
//Description : 로그아웃 기능에 대한 control 클래스 역할을 하는 클래스
//Created : 2017/05/30 3:20 am
//Author : 조현정
//mail : guswjd8718@naver.com

class Logout
{
private:
	UserCollection* userCollectionPointer;
	LogoutUI* logoutPointer;

public:
	void callLoginOnOff(string idOfUser);

	Logout(UserCollection& userCollection);
	~Logout();

	LogoutUI* callLogoutUIStartInterface(Logout& logout);
};

