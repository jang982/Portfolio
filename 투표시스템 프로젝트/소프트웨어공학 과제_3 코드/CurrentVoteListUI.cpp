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
// Description:  CurrentVoteList(��Ʈ�� Ŭ����)�� ����� �޾� UI�� ����
// Parameters : CurrentVoteList&
// Return Value : CurrentVoteList*
// Created: 2017/5/24 13:30pm
// Author: ȫ����
//
CurrentVoteListUI * CurrentVoteListUI::startInterface(CurrentVoteList & currentVoteList)
{
	CurrentVoteListUI* newPointer = new CurrentVoteListUI(currentVoteList);
	return newPointer;
}
// Function : confirmView
// Description:  Vote �������� ������
// Parameters : string* int* string* string* string* 
// Return Value : 
// Created: 2017/5/24 13:30pm
// Author: ȫ����
//
void CurrentVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime,string * belongsTo)
{
	currentVoteListPointer->showVoteList(subject, items, startTime, endTime, belongsTo);
}
