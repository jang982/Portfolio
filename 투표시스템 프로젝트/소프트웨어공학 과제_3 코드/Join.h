#pragma once
#include<string>
#include<iostream>
#include<list>
using namespace std;

class UserCollection;
class JoinUI;

// Class : Join
// Description: 회원가입 할 때의 control 클래스 역할을 하는 클래스
// Created: 2017/5/29 7:00 pm
// Author: 조현정
// mail: guswjd8718@naver.com
//

class Join
{
private:
	UserCollection* userCollectionPointer;
	JoinUI* joinUIPointer;
	bool isExists;

public:
	Join(UserCollection& userCollection);
	~Join();

	JoinUI* callJoinUIStartInterface(Join& join);
	bool callCreateUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd);
	void checkExists(string idOfUser);
};

