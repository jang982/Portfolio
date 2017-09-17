#include "ShowJoinedGroupUI.h"
#include "ShowJoinedGroup.h"
#include "User.h"

//Class: ShowJoinedGroupUI
//Description: ShowJoinedGroupUI 구현
//created: 2017/5/30 08:30am
//Author: 장현석
//mail: jang8018@naver.com


// Function : ShowJoinedGroupUI(ShowJoinedGroup &showJoinedGroup)
// Description: 컨트롤을 받아 넘겨주면서 UI를 생성합니다.
// Parameters : ShowJoinedGroup &showJoinedGroup
// Return Value : void
//
// Created: 2017/5/30 08:30am
// Author: 장현석
//
ShowJoinedGroupUI::ShowJoinedGroupUI(ShowJoinedGroup &showJoinedGroup)
{
	showJoinedGroupPointer = &showJoinedGroup;
}


ShowJoinedGroupUI::~ShowJoinedGroupUI()
{
}


// Function : confirmView(list<User>::iterator loginUser, string &joinedGroupName)
// Description: 받은 스트링을 넘겨주면서 컨트롤에 showJoinedGroup호출을 요청합니다.
// Parameters : list<User>::iterator loginUser, string &joinedGroupName
// Return Value : bool
//
// Created: 2017/5/30 08:32am
// Author: 장현석
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
// Author: 장현석
//
ShowJoinedGroupUI * ShowJoinedGroupUI::startInterface(ShowJoinedGroup & showJoinedGroup)
{
	ShowJoinedGroupUI* newPointer = new ShowJoinedGroupUI(showJoinedGroup);
	return newPointer;
}
