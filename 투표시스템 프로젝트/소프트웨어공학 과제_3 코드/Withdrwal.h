#include <string>
#include <iostream>
#include <list>

using namespace std;

class UserCollection;
class WithdrwalUI;
class User;

// Class : Withdrwal
// Description: 회원탈퇴 기능에서 control클래스의 역할을 하는 클래스
// Created: 2017/5/30 2:36 pm
// Author: 조현정
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