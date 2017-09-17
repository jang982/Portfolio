#include "ShowAllGroupUI.h"
#include "ShowAllGroup.h"


//Class: ShowAllGroupUI
//Description: ShowAllGroupUI 구현
//created: 2017/5/29 09:10am
//Author: 장현석
//mail: jang8018@naver.com


// Function : ShowAllGroupUI(ShowAllGroup &showAllGroup)
// Description: 컨트롤 주소를받아 포인터를 지정하고, UI를 생성합니다.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : void
//
// Created: 2017/5/29 09:10am
// Author: 장현석
//
ShowAllGroupUI::ShowAllGroupUI(ShowAllGroup &showAllGroup)
{
	showAllGroupPointer = &showAllGroup;
}


ShowAllGroupUI::~ShowAllGroupUI()
{

}



// Function : confirmView(string* groupList)
// Description: 문자열배열을 전달받아 컨트롤로 넘겨주면서 showAllGroup을 호출합니다.
// Parameters : string* groupList
// Return Value : void
//
// Created: 2017/5/29 09:20am
// Author: 장현석
//
void ShowAllGroupUI::confirmView(string* groupList)
{
	showAllGroupPointer->showAllGroup(groupList);
}


// Function : startInterface(ShowAllGroup &showAllGroup)
// Description: 컨트롤을 받아 UI에 넘겨주면서 생성자를 호출합니다.
// Parameters : ShowAllGroup &showAllGroup
// Return Value : ShowAllGroupUI*
//
// Created: 2017/5/29 09:22am
// Author: 장현석
//
ShowAllGroupUI* ShowAllGroupUI::startInterface(ShowAllGroup &showAllGroup)
{
	ShowAllGroupUI* newPointer = new ShowAllGroupUI(showAllGroup);
	return newPointer;
}
