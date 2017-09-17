#pragma once
#include<string>
#include<list>
#include<iostream>

using namespace std;

class Login;
class User;
class UserCollection;

// Class : LoginUI
// Description: 로그인 기능에 대해 boundary클래스의 역할을 하는 클래스
// Created: 2017/5/30 2:10 am
// Author: 조현정
// mail: guswjd8718@naver.com
//
class LoginUI
{
private:
	Login* loginPointer;
public:
	static LoginUI* startInterface(Login& login);
	bool getUserInfo(string inputID, string inputPwd, list<User>::iterator allUser);

	LoginUI(Login& login);
	~LoginUI();
};

