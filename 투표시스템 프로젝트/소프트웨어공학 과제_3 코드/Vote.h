#pragma once

#include <iostream>
#include <string>
#include <list>
#define MAX_LIST 100

//Class: Vote
//Description: Vote 헤더
//created: 2017/5/24 20:00pm
//Author: 홍유남
//mail: bcdass@naver.com


using namespace std;

class Vote;

//extern list<Vote> VoteList;

class Vote {
private:
	string			subject;
	int				items[MAX_LIST];
	string			startTime;
	string			endTime;

	string			personalNumberList[MAX_LIST];	// 재투표 방지를 위해서, 투표했던 사람들의 personal number(중복 안되게)
	string			belongsTo;						// 속한 그룹 이름

public:
	Vote(string subjectOfVote, int items, string startTime, string endTime,string groupName);
	~Vote();

	static Vote*	createVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firsrEndTime, string groupName);// 투표 생성
	void			deleteVote();// 투표삭제
	int			doVoteFor(int itemNuber, string personalNumber);

	string			getSubject();
	void			setSubject(string inputSubject);
	int				getItems();
	void			setItems(int inputItems);
	string			getStartTime();
	void			setStartTime(string inputStartTime);
	string			getEndTime();
	void			setEndTime(string inputEndTime);
	string			getBelongsTo();
	void			setBelongsTo(string inputBelongsTo);

	int*			getResult();
};

