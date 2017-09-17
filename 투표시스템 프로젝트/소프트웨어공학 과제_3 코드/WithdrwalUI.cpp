#include "WithdrwalUI.h"
#include "Withdrwal.h"
#include "UserCollection.h"

// Function : WithdrwalUI(Withdrwal& withdrwal)
// Description: WithdrwalUI�� �������ִ� ������
// Parameters : Withdrwal& withdrwal
// Return Value : none.
//
// Created: 2017/5/30 3:50 pm
// Author: ������
//
WithdrwalUI::WithdrwalUI(Withdrwal& withdrwal)
{
	withdrwalPointer = &withdrwal;
}

// Function : WithdrwalUI* startInterface(Withdrwal& withdrwal)
// Description: WithdrwalUI�� �����ϴ� startInterface�Լ�
// Parameters : WithdrwalUI
// Return Value : Withdrwal& withdrwal
//
// Created: 2017/5/30 3:56 pm
// Author: ������
//
WithdrwalUI * WithdrwalUI::startInterface(Withdrwal & withdrwal)
{
	WithdrwalUI* newPointer = new WithdrwalUI(withdrwal);
	return newPointer;
}

// Function : bool clickWithdrwal(string idOfUser)
// Description: callDestroyUser�� ����� ��ȯ�ϴ� �Լ�
// Parameters : bool
// Return Value : Withdrwal& withdrwal
//
// Created: 2017/5/30 3:56 pm
// Author: ������
//
bool WithdrwalUI::clickWithdrwal(string idOfUser)
{
	return withdrwalPointer->callDestroyUser(idOfUser);
}


// Function : WithdrwalUI(Withdrwal& withdrwal)
// Description: WithdrwalUI�� �ı��ϴ� �Ҹ���
// Parameters : void
// Return Value : none.
//
// Created: 2017/5/30 3:52 pm
// Author: ������
//
WithdrwalUI::~WithdrwalUI()
{

}
