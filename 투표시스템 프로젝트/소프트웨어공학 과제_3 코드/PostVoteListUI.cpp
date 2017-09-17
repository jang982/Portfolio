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
// Description:  PostVoteList(컨트롤 클래스)의 명령을 받아 UI를 생성
// Parameters : PostVoteList&
// Return Value : PostVoteList*
// Created: 2017/5/24 12:50pm
// Author: 홍유남
//

PostVoteListUI * PostVoteListUI::startInterface(PostVoteList & postVoteList)
{
	PostVoteListUI* newPointer = new PostVoteListUI(postVoteList);
	return newPointer;
}
// Function : confirmView
// Description:  Vote 정보값을 보여줌
// Parameters : string* int* string* string* string*
// Return Value : 
// Created: 2017/5/24 12:50pm
// Author: 홍유남
//

void PostVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime,string * belonsTo)
{
	postVoteListPointer->showVoteList(subject, items, startTime, endTime, belonsTo);
}
