#pragma once
#include<string>
#include<list>
#include<iostream>
using namespace std;
class Join;
class User;

// Class : JoinUI
// Description: 회원가입 할 때의 boundary 클래스 역할을 하는 클래스
// Created: 2017/5/29 7:20 pm
// Author: 조현정
// mail: guswjd8718@naver.com
//

class JoinUI
{
private:
	Join* joinPointer;
public:
	JoinUI(Join& join);
	~JoinUI();

	static JoinUI* startInterface(Join& join);
	bool enterUserInfo(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd);
};

