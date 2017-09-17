#pragma once

#include <iostream>
#include <string>
#include <list>

//Class: VoteCollection
//Description: VoteCollection �Լ�
//created: 2017/5/29 10:00
//Author: ȫ����
//mail: bcdass@naver.com


using namespace std;

class Vote;

class VoteCollection {
private:
	list<Vote> voteList;
	list<Vote>::iterator voteListIterator;
public:
	list<Vote>::iterator	findFirst();
	list<Vote>::iterator	getNext(list<Vote>::iterator &inputIter);
	list<Vote>::iterator	findEnd();
	
	void					addVote(string subjectOfVote, int numberOfItems, string firstStartTime, string firsrEndTime, string groupName); //���ο� vote ����
	list<Vote>*				getVoteListHead();
	

	VoteCollection();
	~VoteCollection();
};

