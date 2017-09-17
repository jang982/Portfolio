#include "Join.h"
#include "JoinUI.h"
#include"UserCollection.h"
#include"User.h"

// Function : Join(UserCollection& userCollection)
// Description: Join class�� ������
// Parameters : UserCollection& userCollection
// Return Value : void
//
// Created: 2017/5/29 7:5 pm
// Author: ������
//
Join::Join(UserCollection& userCollection)
{
	userCollectionPointer = &userCollection;
}

// Function : ~Join()
// Description: Join class�� �Ҹ���
// Parameters : void
// Return Value : void
//
// Created: 2017/5/29 7:7 pm
// Author: ������
//
Join::~Join()
{
}

// Function : bool callCreateUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
// Description: ������ üũ(�ߺ��Ǵ� ���̵� �ƴ���)�Ͽ� ���ǿ� �����Ѵٸ� userCollection�� addUser�� ȣ���ϴ� �Լ�.
// Parameters : string newName, string newPersonalNumber, string newAddress, string newID, string newPwd
// Return Value : bool
//
// Created: 2017/5/29 7:10 pm
// Author: ������
//
bool Join::callCreateUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	checkExists(newID);
	if (isExists)
		return 1;
	else {
		userCollectionPointer->addUser(newName, newPersonalNumber,newAddress, newID, newPwd);
		return 0;
	}
}

// Function : checkExists(string idOfUser)
// Description: �ߺ��Ǵ� ���̵� �ִ��� üũ���ִ� �Լ�
// Parameters : string idOfUser
// Return Value : void
//
// Created: 2017/5/29 7:15 pm
// Author: ������
//
void Join::checkExists(string idOfUser)
{
	list<User>::iterator iter = userCollectionPointer->findUser(idOfUser);
	if (iter == userCollectionPointer->findEnd())
		isExists = false;
	else
		isExists = true;
}

// Function : callJoinUIStartInterface(Join& join)
// Description: JoinUI�� �������̽��� ��ȯ���ִ� �Լ�
// Parameters : Join& join
// Return Value : JoinUI*
//
// Created: 2017/5/29 7:18 pm
// Author: ������
//
JoinUI* Join::callJoinUIStartInterface(Join& join)
{
	return JoinUI::startInterface(join);
}
