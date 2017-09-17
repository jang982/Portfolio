#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Withdrwal;
class User;
class UserCollection;

// Class : WithdrwalUI
// Description: 회원탈퇴 기능에 대해 boundary 클래스의 역할을 하는 클래스
// Created: 2017/5/30 2:40 pm
// Author: 조현정
// mail: guswjd8718@naver.com
//


class WithdrwalUI
{
private:
	Withdrwal* withdrwalPointer;

public:
	static WithdrwalUI* startInterface(Withdrwal& withdrwal);
	bool clickWithdrwal(string idOfUser);

	WithdrwalUI(Withdrwal& withdrwal);
	~WithdrwalUI();
};

