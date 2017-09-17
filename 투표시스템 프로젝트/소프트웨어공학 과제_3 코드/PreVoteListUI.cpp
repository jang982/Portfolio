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
// Description:  PreVoteList(��Ʈ�� Ŭ����)�� ����� �޾� UI�� ����
// Parameters : PreVoteList&
// Return Value : PreVoteList*
// Created: 2017/5/24 11:00pm
// Author: ȫ����
//
PreVoteListUI * PreVoteListUI::startInterface(PreVoteList & preVoteList)
{
	PreVoteListUI* newPointer = new PreVoteListUI(preVoteList);
	return newPointer;
}

// Function : confirmView
// Description:  Vote �������� ������
// Parameters : string* int* string* string* string* int**
// Return Value : PreVoteList*
// Created: 2017/5/24 11:00pm
// Author: ȫ����
//

void PreVoteListUI::confirmView(string * subject, int * items, string * startTime, string * endTime, string * belongsTo, int ** result)
{
	preVoteListPointer->showVoteList(subject, items, startTime, endTime, belongsTo, result);
}

// Function : weakLater
// Description:  4�ְ� �������� PreVoteList(��Ʈ�� Ŭ����)�� �˷��ִ� �Լ�
// Parameters : string
// Return Value : 
// Created: 2017/5/24 11:00pm
// Author: ȫ����
//

void PreVoteListUI::weekLater(string endTime)
{
	preVoteListPointer->deleteVoteMessage(endTime);
}
