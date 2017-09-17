#include "ShowJoinedGroup.h"
#include "UserCollection.h"
#include "ShowJoinedGroupUI.h"
#include "User.h"

//Class: ShowJoinedGroup
//Description: ShowJoinedGroup ����
//created: 2017/5/30 08:10am
//Author: ������
//mail: jang8018@naver.com



ShowJoinedGroup::ShowJoinedGroup()
{
}


ShowJoinedGroup::~ShowJoinedGroup()
{
}


// Function : callShowJoinedGroupUIStartInterface(ShowJoinedGroup & showJoinedGroup)
// Description: ��Ʈ���� �޾� �Ѱ��ָ鼭 UI�������̽��� ȣ���մϴ�.
// Parameters : ShowJoinedGroup & showJoinedGroup
// Return Value : ShowJoinedGroupUI *
//
// Created: 2017/5/30 08:10am
// Author: ������
//
ShowJoinedGroupUI * ShowJoinedGroup::callShowJoinedGroupUIStartInterface(ShowJoinedGroup & showJoinedGroup)
{
	return ShowJoinedGroupUI::startInterface(showJoinedGroup);
}


// Function : showJoinedGroup(list<User>::iterator loginUser, string& joinedGroupName)
// Description: ������ ���� �׷��̸��� �Ѱܹ��� ��Ʈ���� �����ϰ�, ����� ��ȯ�մϴ�.
// Parameters : list<User>::iterator loginUser, string& joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 08:15am
// Author: ������
//
bool ShowJoinedGroup::showJoinedGroup(list<User>::iterator loginUser, string& joinedGroupName)
{
	if (loginUser->getJoinedGroup() == "none")
	{
		return true;
	}
	else
	{
		joinedGroupName = loginUser->getJoinedGroup();
		return false;
	}

}
