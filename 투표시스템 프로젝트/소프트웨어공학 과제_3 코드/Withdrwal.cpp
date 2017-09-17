#include "Withdrwal.h"
#include "WithdrwalUI.h"
#include "UserCollection.h"
#include "User.h"


// Function : void calDestroyUser(string idOfUser)
// Description: ȸ��Ż�� �� �� �ִ��� ������ �Ǻ��Ͽ� removeUser�Լ��� �ҷ��ִ� �Լ�
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:09 pm
// Author: ������
//
bool Withdrwal::callDestroyUser(string idOfUser)
{
	checkLeader(idOfUser);
	if (isExists)
	{
		//ȸ��Ż�� ����
		return 1;
	}
	else
	{
		//ȸ��Ż�� ����
		userCollectionPointer->removeUser(idOfUser);
		return 0;
	}
}

// Function : void checkLeader(string idOfUser)
// Description: �������� �ƴ��� �Ǻ��Ͽ� ȸ��Ż�� ������.
// Parameters :   string idOfUser
// Return Value : void
//
// Created: 2017/5/30 3:45 pm
// Author: ������
//

void Withdrwal::checkLeader(string idOfUser)
{
	list<User>::iterator iter = userCollectionPointer->findUser(idOfUser);
	if (iter == userCollectionPointer->findEnd()) //�������� �ʴ� ���̵�. ȸ��Ż�� ��� ��ü ���̿���.
		isExists = true;
	else
	{
		if (iter->getIsLeader() == false)
		{
			//�׷����� �ƴϹǷ� ȸ�� Ż�� ����
			isExists = false;
		}
		else
		{
			//�׷����̹Ƿ� ȸ��Ż�� ����
			isExists = true;
		}
			
	}
}

// Function : Withdrwal(UserCollection& userCOllection)
// Description: WithdrwalŬ������ ������
// Parameters :   UserCollection& userCollection
// Return Value : none.
//
// Created: 2017/5/30 3:07 pm
// Author: ������
//
Withdrwal::Withdrwal(UserCollection & userCollection)
{
	userCollectionPointer = &userCollection;
}


// Function : ~Withdrwal(UserCollection& userCOllection)
// Description: LogoutŬ������ �Ҹ���
// Parameters :   void
// Return Value : none.
//
// Created: 2017/5/30 3:08 pm
// Author: ������
//
Withdrwal::~Withdrwal()
{
}

// Function : void callWithdrwalUIStartInterface(Withdrwal& withdrwal)
// Description: ȸ��Ż��UI�� interface�� ��ȯ���ִ� �Լ�
// Parameters : Withdrwal& withdrwal;
// Return Value : WithdrwalUI*
//
// Created: 2017/5/30 3:40pm
// Author: ������
//
WithdrwalUI * Withdrwal::callWithdrwalUIStartInterface(Withdrwal & withdrwal)
{
	return WithdrwalUI::startInterface(withdrwal);
}
