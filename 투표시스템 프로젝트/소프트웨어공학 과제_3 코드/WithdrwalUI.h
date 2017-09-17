#pragma once

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Withdrwal;
class User;
class UserCollection;

// Class : WithdrwalUI
// Description: ȸ��Ż�� ��ɿ� ���� boundary Ŭ������ ������ �ϴ� Ŭ����
// Created: 2017/5/30 2:40 pm
// Author: ������
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

