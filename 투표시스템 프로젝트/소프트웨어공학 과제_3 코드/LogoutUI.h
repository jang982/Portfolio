#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Logout;
class User;
class UserCollection;

//Class : LogoutUI
//Description : 로그아웃 기능의 boundary클래스 역할을 하는 클래스
//Created 2017/05/30 3:25 am
//Author : 조현정
//mail : guswjd8718@naver.com
class LogoutUI
{
private:
	Logout* logoutPointer;

public:
	static LogoutUI* startInterface(Logout& logout);
	void clickLogout(string idOfUser);

	LogoutUI(Logout& logout);
	~LogoutUI();
};

