#include "ShowJoinedGroup.h"
#include "UserCollection.h"
#include "ShowJoinedGroupUI.h"
#include "User.h"

//Class: ShowJoinedGroup
//Description: ShowJoinedGroup 구현
//created: 2017/5/30 08:10am
//Author: 장현석
//mail: jang8018@naver.com



ShowJoinedGroup::ShowJoinedGroup()
{
}


ShowJoinedGroup::~ShowJoinedGroup()
{
}


// Function : callShowJoinedGroupUIStartInterface(ShowJoinedGroup & showJoinedGroup)
// Description: 컨트롤을 받아 넘겨주면서 UI인터페이스를 호출합니다.
// Parameters : ShowJoinedGroup & showJoinedGroup
// Return Value : ShowJoinedGroupUI *
//
// Created: 2017/5/30 08:10am
// Author: 장현석
//
ShowJoinedGroupUI * ShowJoinedGroup::callShowJoinedGroupUIStartInterface(ShowJoinedGroup & showJoinedGroup)
{
	return ShowJoinedGroupUI::startInterface(showJoinedGroup);
}


// Function : showJoinedGroup(list<User>::iterator loginUser, string& joinedGroupName)
// Description: 유저가 속한 그룹이름을 넘겨받은 스트링에 저장하고, 결과를 반환합니다.
// Parameters : list<User>::iterator loginUser, string& joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 08:15am
// Author: 장현석
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
