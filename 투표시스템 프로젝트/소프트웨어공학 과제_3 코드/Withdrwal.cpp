#include "Withdrwal.h"
#include "WithdrwalUI.h"
#include "UserCollection.h"
#include "User.h"


// Function : void calDestroyUser(string idOfUser)
// Description: 회원탈퇴를 할 수 있는지 없는지 판별하여 removeUser함수를 불러주는 함수
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:09 pm
// Author: 조현정
//
bool Withdrwal::callDestroyUser(string idOfUser)
{
	checkLeader(idOfUser);
	if (isExists)
	{
		//회원탈퇴 실패
		return 1;
	}
	else
	{
		//회원탈퇴 성공
		userCollectionPointer->removeUser(idOfUser);
		return 0;
	}
}

// Function : void checkLeader(string idOfUser)
// Description: 리더인지 아닌지 판별하여 회원탈퇴를 진행함.
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:45 pm
// Author: 조현정
//

void Withdrwal::checkLeader(string idOfUser)
{
	list<User>::iterator iter = userCollectionPointer->findUser(idOfUser);
	if (iter == userCollectionPointer->findEnd()) //존재하지 않는 아이디. 회원탈퇴 기능 자체 못이용함.
		isExists = true;
	else
	{
		if (iter->getIsLeader() == false)
		{
			//그룹장이 아니므로 회원 탈퇴 성공
			isExists = false;
		}
		else
		{
			//그룹장이므로 회원탈퇴 실패
			isExists = true;
		}
			
	}
}

// Function : Withdrwal(UserCollection& userCOllection)
// Description: Withdrwal클래스의 생성자
// Parameters :   UserCollection& userCollection
// Return Value : none.
//
// Created: 2017/5/30 3:07 pm
// Author: 조현정
//
Withdrwal::Withdrwal(UserCollection & userCollection)
{
	userCollectionPointer = &userCollection;
}


// Function : ~Withdrwal(UserCollection& userCOllection)
// Description: Logout클래스의 소멸자
// Parameters :   void
// Return Value : none.
//
// Created: 2017/5/30 3:08 pm
// Author: 조현정
//
Withdrwal::~Withdrwal()
{
}

// Function : void callWithdrwalUIStartInterface(Withdrwal& withdrwal)
// Description: 회원탈퇴UI의 interface를 반환해주는 함수
// Parameters : Withdrwal& withdrwal;
// Return Value : WithdrwalUI*
//
// Created: 2017/5/30 3:40pm
// Author: 조현정
//
WithdrwalUI * Withdrwal::callWithdrwalUIStartInterface(Withdrwal & withdrwal)
{
	return WithdrwalUI::startInterface(withdrwal);
}
