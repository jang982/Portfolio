#include "ShowJoinedGroupUI.h"
#include "ShowJoinedGroup.h"
#include "User.h"

//Class: ShowJoinedGroupUI
//Description: ShowJoinedGroupUI ����
//created: 2017/5/30 08:30am
//Author: ������
//mail: jang8018@naver.com


// Function : ShowJoinedGroupUI(ShowJoinedGroup &showJoinedGroup)
// Description: ��Ʈ���� �޾� �Ѱ��ָ鼭 UI�� �����մϴ�.
// Parameters : ShowJoinedGroup &showJoinedGroup
// Return Value : void
//
// Created: 2017/5/30 08:30am
// Author: ������
//
ShowJoinedGroupUI::ShowJoinedGroupUI(ShowJoinedGroup &showJoinedGroup)
{
	showJoinedGroupPointer = &showJoinedGroup;
}


ShowJoinedGroupUI::~ShowJoinedGroupUI()
{
}


// Function : confirmView(list<User>::iterator loginUser, string &joinedGroupName)
// Description: ���� ��Ʈ���� �Ѱ��ָ鼭 ��Ʈ�ѿ� showJoinedGroupȣ���� ��û�մϴ�.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 08:32am
// Author: ������
//
bool ShowJoinedGroupUI::confirmView(list<User>::iterator loginUser, string &joinedGroupName)
{
	return showJoinedGroupPointer->showJoinedGroup(loginUser,joinedGroupName);
}


// Function : startInterface(ShowJoinedGroup & showJoinedGroup)
// Description: 
// Parameters : ShowJoinedGroup & showJoinedGroup
// Return Value : ShowJoinedGroupUI *
//
// Created: 2017/5/30 08:36am
// Author: ������
//
ShowJoinedGroupUI * ShowJoinedGroupUI::startInterface(ShowJoinedGroup & showJoinedGroup)
{
	ShowJoinedGroupUI* newPointer = new ShowJoinedGroupUI(showJoinedGroup);
	return newPointer;
}
