#include "ShowAllGroupUI.h"
#include "ShowAllGroup.h"


//Class: ShowAllGroupUI
//Description: ShowAllGroupUI ����
//created: 2017/5/29 09:10am
//Author: ������
//mail: jang8018@naver.com


// Function : ShowAllGroupUI(ShowAllGroup &showAllGroup)
// Description: ��Ʈ�� �ּҸ��޾� �����͸� �����ϰ�, UI�� �����մϴ�.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : void
//
// Created: 2017/5/29 09:10am
// Author: ������
//
ShowAllGroupUI::ShowAllGroupUI(ShowAllGroup &showAllGroup)
{
	showAllGroupPointer = &showAllGroup;
}


ShowAllGroupUI::~ShowAllGroupUI()
{

}



// Function : confirmView(string* groupList)
// Description: ���ڿ��迭�� ���޹޾� ��Ʈ�ѷ� �Ѱ��ָ鼭 showAllGroup�� ȣ���մϴ�.
// Parameters : string* groupList
// Return Value : void
//
// Created: 2017/5/29 09:20am
// Author: ������
//
void ShowAllGroupUI::confirmView(string* groupList)
{
	showAllGroupPointer->showAllGroup(groupList);
}


// Function : startInterface(ShowAllGroup &showAllGroup)
// Description: ��Ʈ���� �޾� UI�� �Ѱ��ָ鼭 �����ڸ� ȣ���մϴ�.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : ShowAllGroupUI*
//
// Created: 2017/5/29 09:22am
// Author: ������
//
ShowAllGroupUI* ShowAllGroupUI::startInterface(ShowAllGroup &showAllGroup)
{
	ShowAllGroupUI* newPointer = new ShowAllGroupUI(showAllGroup);
	return newPointer;
}
