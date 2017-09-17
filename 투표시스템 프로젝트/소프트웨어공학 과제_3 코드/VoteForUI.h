#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

class VoteFor;
//Class: VoteForUI
//Description: 투표 기능(VoteFor)의 boundary 클래스 역할을 수행함.
//created: 2017/6/1 15:00pm
//Author: 김윤영
//mail: kyy01114@hanmail.net

class VoteForUI
{
private:
	VoteFor* voteForPointer;

public:
	static VoteForUI* startInterface(VoteFor &voteFor);
	//Function: static VoteForUI* startInterface(VoteFor &voteFor);
	//Description: control class에 의해 startinterface는 수행된다.
	//Parameters: VoteFor& voteFor - 투표 기능(votefor)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	int inputData(string subject, int itemNumber,string joinedGroup, string personalNumber);
	//Function: int inputData(string subject, int itemNumber,string joinedGroup, string personalNumber)
	//Description: 필요한 데이터를 control로 넘기는 기능을 수행한다.
	//Parameters: VoteFor& voteFor - 투표 기능(votefor)의 control class
	//Return Value: error value, 2가지 error와 1가지 성공, 총 3가지를 구분하기 위해 int를 사용
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	VoteForUI(VoteFor &voteFor);
	~VoteForUI();
	//Function: VoteForUI(VoteFor &voteFor), ~VoteForUI()
	//Description: 생성자와 소멸자, UI는 control에 의해 생성된다.
	//Parameters: VoteFor& voteFor - 투표 기능(votefor)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm
};

