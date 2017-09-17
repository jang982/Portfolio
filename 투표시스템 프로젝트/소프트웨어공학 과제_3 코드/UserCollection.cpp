#include "UserCollection.h"
#include "User.h"

//Class: UserCollection
//Description: UserCollection ����
//created: 2017/5/27 21:00pm
//Author: ������
//mail: jang8018@naver.com


//����
//1. 2017/05/30 3:36 am by������
//setLoginOff �Լ� �߰�
//����
//2. 2017/05/30 3:11 pm by ������
//removeUser�Լ� �߰�
//extern�� ��������Ʈ �ҷ�����


UserCollection::UserCollection(){}
UserCollection::~UserCollection(){}

//Function: list<User>::iterator findFirst()
//Description: ���� ����Ʈ�� ù��° �ݺ��ڸ� ��ȯ�Ѵ�.
//created: 2017/5/27 21:03pm
//Author: ������
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findFirst()
{
	userListIterator = userList.begin();
	return userListIterator;
}

//Function: list<User>::iterator findEnd()
//Description: ���� ����Ʈ�� ���� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
//created: 2017/5/27 21:05pm
//Author: ������
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findEnd()
{
	userListIterator = userList.end();
	return userListIterator;
}

//Function: list<User>::iterator getNext(list<User>::iterator &inputIter)
//Description: ���� ����Ʈ�� �ݺ��ڸ� �������� �̵������ش�.
//created: 2017/5/27 21:07pm
//Author: ������
//mail: jang8018@naver.com
list<User>::iterator UserCollection::getNext(list<User>::iterator &inputIter)
{
	return inputIter++;
}

//Function: list<User>::iterator findUser(string idOfUser)
//Description: ���� ����Ʈ���� �ش��ϴ� ���̵��� �ݺ��ڸ� ������.
//created: 2017/5/27 21:10pm
//Author: ������
//mail: jang8018@naver.com
list<User>::iterator UserCollection::findUser(string idOfUser)
{
	userListIterator = userList.begin();
	bool success = false;											//��������

																	//����Ʈ �˻�
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
//Description: ���� ����Ʈ�� ���ο� ������ �߰��Ѵ�.
//created: 2017/5/27 21:14pm
//Author: ������
//mail: jang8018@naver.com
void UserCollection::addUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	userList.push_back(*User::createUser(newName,newPersonalNumber,newAddress,newID,newPwd));
}


// Function : void removeUser(string idOfUser)
// Description: ������ �Ҹ��ϰ� ����Ʈ���� �������ִ� �Լ�
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:20 pm
// Author: ������
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
//Description: ������ �α��� ���¸� �α������� �ٲ۴�.
//created: 2017/5/27 21:17pm
//Author: ������
//mail: jang8018@naver.com
void UserCollection::setLoginUser(string idOfUser)
{
	list<User>::iterator iter = UserCollection::findUser(idOfUser);
	iter->setLoginOn();
}
// Function : void setLogOinffUser(string idOfUser)
// Description: ������ setLoginOff�Լ��� ȣ�����ִ� �Լ�
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:39 am
// Author: ������
//
void UserCollection::setLoginOffUser(string idOfUser)
{
	list<User>::iterator iter = UserCollection::findUser(idOfUser);
	iter->setLoginOff();
}