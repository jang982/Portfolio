#include "UserCollection.h"
#include "User.h"

//Class: UserCollection
//Description: UserCollection 구현
//created: 2017/5/27 21:00pm
//Author: 장현석
//mail: jang8018@naver.com


//수정
//1. 2017/05/30 3:36 am by조현정
//setLoginOff 함수 추가
//수정
//2. 2017/05/30 3:11 pm by 조현정
//removeUser함수 추가
//extern된 유저리스트 불러오기


UserCollection::UserCollection(){}
UserCollection::~UserCollection(){}

//Function: list<User>::iterator findFirst()
//Description: 유저 리스트에 첫번째 반복자를 반환한다.
//created: 2017/5/27 21:03pm
//Author: 장현석
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findFirst()
{
	userListIterator = userList.begin();
	return userListIterator;
}

//Function: list<User>::iterator findEnd()
//Description: 유저 리스트에 끝을 가리키는 반복자를 반환한다.
//created: 2017/5/27 21:05pm
//Author: 장현석
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findEnd()
{
	userListIterator = userList.end();
	return userListIterator;
}

//Function: list<User>::iterator getNext(list<User>::iterator &inputIter)
//Description: 유저 리스트의 반복자를 다음으로 이동시켜준다.
//created: 2017/5/27 21:07pm
//Author: 장현석
//mail: jang8018@naver.com
list<User>::iterator UserCollection::getNext(list<User>::iterator &inputIter)
{
	return inputIter++;
}

//Function: list<User>::iterator findUser(string idOfUser)
//Description: 유저 리스트에서 해당하는 아이디의 반복자를 리턴함.
//created: 2017/5/27 21:10pm
//Author: 장현석
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findUser(string idOfUser)
{
	userListIterator = userList.begin();
	bool success = false;											//성공여부

																	//리스트 검색
	for (userListIterator = userList.begin(); userListIterator != userList.end(); userListIterator++)
	{
		if (userListIterator->getUserID() == idOfUser)
		{
			success = true;
			break;
		}
	}

	return userListIterator;
}

//Function: void addUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
//Description: 유저 리스트에 새로운 유저를 추가한다.
//created: 2017/5/27 21:14pm
//Author: 장현석
//mail: jang8018@naver.com
void UserCollection::addUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	userList.push_back(*User::createUser(newName,newPersonalNumber,newAddress,newID,newPwd));
}


// Function : void removeUser(string idOfUser)
// Description: 유저를 소멸하고 리스트에서 삭제해주는 함수
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:20 pm
// Author: 조현정
//
void UserCollection::removeUser(string idOfUser)
{
	userListIterator = userList.begin();
	bool find = false;

	for (userListIterator = userList.begin(); userListIterator != userList.end(); userListIterator++)
	{
		if (userListIterator->getUserID() == idOfUser)
		{
			userListIterator->deleteUser();
			userListIterator = userList.erase(userListIterator);
			find = true;
			break;
		}
	}

}

//Function: void setLoginUser(string idOfUser)
//Description: 유저의 로그인 상태를 로그인으로 바꾼다.
//created: 2017/5/27 21:17pm
//Author: 장현석
//mail: jang8018@naver.com
void UserCollection::setLoginUser(string idOfUser)
{
	list<User>::iterator iter = UserCollection::findUser(idOfUser);
	iter->setLoginOn();
}
// Function : void setLogOinffUser(string idOfUser)
// Description: 유저의 setLoginOff함수를 호출해주는 함수
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:39 am
// Author: 조현정
//
void UserCollection::setLoginOffUser(string idOfUser)
{
	list<User>::iterator iter = UserCollection::findUser(idOfUser);
	iter->setLoginOff();
}