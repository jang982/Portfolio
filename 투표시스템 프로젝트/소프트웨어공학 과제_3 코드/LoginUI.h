#pragma once
#include<string>
#include<list>
#include<iostream>

using namespace std;

class Login;
class User;
class UserCollection;

// Class : LoginUI
// Description: �α��� ��ɿ� ���� boundaryŬ������ ������ �ϴ� Ŭ����
// Created: 2017/5/30 2:10 am
// Author: ������
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

