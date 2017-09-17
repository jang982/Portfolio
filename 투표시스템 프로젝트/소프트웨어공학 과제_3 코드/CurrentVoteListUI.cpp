#include "CurrentVoteListUI.h"
#include "CurrentVoteList.h"


CurrentVoteListUI::CurrentVoteListUI(CurrentVoteList &currentVoteList)
{
	currentVoteListPointer = &currentVoteList;
}


CurrentVoteListUI::~CurrentVoteListUI()
{
}
// Function : startInterface
// Description:  CurrentVoteList(컨트롤 클래스)의 명령을 받아 UI를 생성
// Parameters : CurrentVoteList&
// Return Value : CurrentVoteList*
// Created: 2017/5/24 13:30pm
// Author: 홍유남
//
CurrentVoteListUI * CurrentVoteListUI::startInterface(CurrentVoteList & currentVoteList)
{
	CurrentVoteListUI* newPointer = new CurrentVoteListUI(currentVoteList);
	return newPointer;
}
// Function : confirmView
// Description:  Vote 정보값을 보여줌
// Parameters : string* int* string* string* string* 
// Return Value : 
// Created: 2017/5/24 13:30pm
// Author: 홍유남
//
void CurrentVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime,string * belongsTo)
{
	currentVoteListPointer->showVoteList(subject, items, startTime, endTime, belongsTo);
}
