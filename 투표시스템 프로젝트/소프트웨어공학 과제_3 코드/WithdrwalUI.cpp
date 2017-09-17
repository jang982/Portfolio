#include "WithdrwalUI.h"
#include "Withdrwal.h"
#include "UserCollection.h"

// Function : WithdrwalUI(Withdrwal& withdrwal)
// Description: WithdrwalUI를 생성해주는 생성자
// Parameters : Withdrwal& withdrwal
// Return Value : none.
//
// Created: 2017/5/30 3:50 pm
// Author: 조현정
//
WithdrwalUI::WithdrwalUI(Withdrwal& withdrwal)
{
	withdrwalPointer = &withdrwal;
}

// Function : WithdrwalUI* startInterface(Withdrwal& withdrwal)
// Description: WithdrwalUI를 시작하는 startInterface함수
// Parameters : WithdrwalUI
// Return Value : Withdrwal& withdrwal
//
// Created: 2017/5/30 3:56 pm
// Author: 조현정
//
WithdrwalUI * WithdrwalUI::startInterface(Withdrwal & withdrwal)
{
	WithdrwalUI* newPointer = new WithdrwalUI(withdrwal);
	return newPointer;
}

// Function : bool clickWithdrwal(string idOfUser)
// Description: callDestroyUser의 결과를 반환하는 함수
// Parameters : bool
// Return Value : Withdrwal& withdrwal
//
// Created: 2017/5/30 3:56 pm
// Author: 조현정
//
bool WithdrwalUI::clickWithdrwal(string idOfUser)
{
	return withdrwalPointer->callDestroyUser(idOfUser);
}


// Function : WithdrwalUI(Withdrwal& withdrwal)
// Description: WithdrwalUI를 파괴하는 소멸자
// Parameters : void
// Return Value : none.
//
// Created: 2017/5/30 3:52 pm
// Author: 조현정
//
WithdrwalUI::~WithdrwalUI()
{

}
