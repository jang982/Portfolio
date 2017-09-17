#pragma once
#include<string>
#include<list>
#include<iostream>

using namespace std;

class UserCollection;
class LoginUI;
class User;

// Class : Login
// Description: 로그인 기능에 대해 Control클래스 역할을 하는 클래스
// Created: 2017/5/30 2:00 am
// Author: 조현정
// mail: guswjd8718@naver.com
//
class Login
{
private:
	UserCollection* userCollectionPointer;
	LoginUI* loginPointer;
	bool isExists;
public:
	bool callLoginOnOff(string inputID, string inputPwd, list<User>::iterator allUser);
	void checkExists(string inputID, string inputPwd);

	LoginUI* callLoginUIStartInterface(Login& login);

	Login(UserCollection& userCollection);
	~Login();
};

