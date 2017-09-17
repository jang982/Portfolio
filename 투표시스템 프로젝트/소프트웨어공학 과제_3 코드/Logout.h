#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class UserCollection;
class LogoutUI;
class User;


//class : Logout
//Description : �α׾ƿ� ��ɿ� ���� control Ŭ���� ������ �ϴ� Ŭ����
//Created : 2017/05/30 3:20 am
//Author : ������
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

