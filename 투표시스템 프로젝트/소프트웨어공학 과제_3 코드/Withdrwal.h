#include <string>
#include <iostream>
#include <list>

using namespace std;

class UserCollection;
class WithdrwalUI;
class User;

// Class : Withdrwal
// Description: ȸ��Ż�� ��ɿ��� controlŬ������ ������ �ϴ� Ŭ����
// Created: 2017/5/30 2:36 pm
// Author: ������
// mail: guswjd8718@naver.com
//

class Withdrwal {
private:
	UserCollection* userCollectionPointer;
	WithdrwalUI* withdrwalPointer;
	bool isExists;

public:
	bool callDestroyUser(string idOfUser);
	void checkLeader(string idOfUser);

	Withdrwal(UserCollection& userCollection);
	~Withdrwal();

	WithdrwalUI* callWithdrwalUIStartInterface(Withdrwal& withdrwal);
};