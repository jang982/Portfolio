#pragma once
#include<string>
#include<iostream>
#include<list>
using namespace std;

class UserCollection;
class JoinUI;

// Class : Join
// Description: ȸ������ �� ���� control Ŭ���� ������ �ϴ� Ŭ����
// Created: 2017/5/29 7:00 pm
// Author: ������
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

