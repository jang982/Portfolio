#include "PreVoteListUI.h"
#include "PreVoteList.h"


PreVoteListUI::PreVoteListUI(PreVoteList &preVoteList)
{
	preVoteListPointer = &preVoteList;
}


PreVoteListUI::~PreVoteListUI()
{
}

// Function : startInterface
// Description:  PreVoteList(컨트롤 클래스)의 명령을 받아 UI를 생성
// Parameters : PreVoteList&
// Return Value : PreVoteList*
// Created: 2017/5/24 11:00pm
// Author: 홍유남
//
PreVoteListUI * PreVoteListUI::startInterface(PreVoteList & preVoteList)
{
	PreVoteListUI* newPointer = new PreVoteListUI(preVoteList);
	return newPointer;
}

// Function : confirmView
// Description:  Vote 정보값을 보여줌
// Parameters : string* int* string* string* string* int**
// Return Value : PreVoteList*
// Created: 2017/5/24 11:00pm
// Author: 홍유남
//

void PreVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime, string * belongsTo, int ** result)
{
	preVoteListPointer->showVoteList(subject, items, startTime, endTime, belongsTo, result);
}

// Function : weakLater
// Description:  4주가 지난것을 PreVoteList(컨트롤 클래스)에 알려주는 함수
// Parameters : string
// Return Value : 
// Created: 2017/5/24 11:00pm
// Author: 홍유남
//

void PreVoteListUI::weekLater(string endTime)
{
	preVoteListPointer->deleteVoteMessage(endTime);
}
