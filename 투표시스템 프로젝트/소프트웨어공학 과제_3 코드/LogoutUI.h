#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Logout;
class User;
class UserCollection;

//Class : LogoutUI
//Description : �α׾ƿ� ����� boundaryŬ���� ������ �ϴ� Ŭ����
//Created 2017/05/30 3:25 am
//Author : ������
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

