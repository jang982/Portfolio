#pragma once

#include <iostream>
#include <string>
#include <list>
#define MAX_LIST 100

//Class: Vote
//Description: Vote ���
//created: 2017/5/24 20:00pm
//Author: ȫ����
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

	string			personalNumberList[MAX_LIST];	// ����ǥ ������ ���ؼ�, ��ǥ�ߴ� ������� personal number(�ߺ� �ȵǰ�)
	string			belongsTo;						// ���� �׷� �̸�

public:
	Vote(string subjectOfVote, int items, string startTime, string endTime,string groupName);
	~Vote();

	static Vote*	createVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firsrEndTime, string groupName);// ��ǥ ����
	void			deleteVote();// ��ǥ����
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

