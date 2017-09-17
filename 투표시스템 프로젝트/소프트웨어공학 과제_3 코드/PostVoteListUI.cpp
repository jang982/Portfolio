#include "PostVoteListUI.h"
#include "PostVoteList.h"

PostVoteListUI::PostVoteListUI(PostVoteList &postVoteList)
{
	postVoteListPointer = &postVoteList;
}


PostVoteListUI::~PostVoteListUI()
{
}
// Function : startInterface
// Description:  PostVoteList(��Ʈ�� Ŭ����)�� ����� �޾� UI�� ����
// Parameters : PostVoteList&
// Return Value : PostVoteList*
// Created: 2017/5/24 12:50pm
// Author: ȫ����
//

PostVoteListUI * PostVoteListUI::startInterface(PostVoteList & postVoteList)
{
	PostVoteListUI* newPointer = new PostVoteListUI(postVoteList);
	return newPointer;
}
// Function : confirmView
// Description:  Vote �������� ������
// Parameters : string* int* string* string* string*
// Return Value : 
// Created: 2017/5/24 12:50pm
// Author: ȫ����
//

void PostVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime,string * belonsTo)
{
	postVoteListPointer->showVoteList(subject, items, startTime, endTime, belonsTo);
}
