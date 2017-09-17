#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;
class VoteForUI;
class VoteCollection;

//Class: VoteFor
//Description: 투표 기능(VoteFor)의 control 클래스 역할을 수행함.
//created: 2017/6/1 15:00pm
//Author: 김윤영
//mail: kyy01114@hanmail.net

class VoteFor
{
private:
	VoteCollection* voteCollectionPointer;
	VoteForUI* voteForUIPointer;

public:
	VoteFor(VoteCollection &voteCollection);
	~VoteFor();
	//Function: VoteFor(VoteCollection &voteCollection), ~VoteFor()
	//Description: 생성자와 소멸자, 투표(voteFor) control class는 votecollection의 레퍼런스를 가지고 있어야한다.
	//Parameters: VoteCollection &voteCollection - 투표 collection
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm

	int doVote(string subject, int itemNumber, string joinedGroup, string personalNumber);
	//Function: int doVote(string subject, int itemNumber, string joinedGroup, string personalNumber);
	//Description: vote에 있는 dovotefor에 들어가기 전에 error들을 걸러준다.
	//Parameters: string subject - 투표 주제, int itemNumber - 투표하는 항목번호, string joinedGroup - 유저가 가입된 그룹, string personalNumber - 유저의 주민번호
	//Return Value: error value, error을 2가지 error와 성공을 구분하기 위해 int를 사용
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm
	
	VoteForUI* callVoteForUIStartInterface(VoteFor &voteFor);
	//Function: VoteForUI* callVoteForUIStartInterface(VoteFor &voteFor);
	//Description: control class는 입력 받기전 UI를 생성해야된다.
	//Parameters: VoteFor& voteFor - 투표 기능(votefor)의 control class
	//Author: 김윤영
	//Created: 2017/6/1 15:00pm
};

