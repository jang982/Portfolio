#pragma once
#include<string>
#include<list>
#include<iostream>

using namespace std;

class UserCollection;
class LoginUI;
class User;

// Class : Login
// Description: �α��� ��ɿ� ���� ControlŬ���� ������ �ϴ� Ŭ����
// Created: 2017/5/30 2:00 am
// Author: ������
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

