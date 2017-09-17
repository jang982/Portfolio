#pragma once
#include <string>
#include <list>

//Class: currentVoteList
//Description: currentVoteList Ŭ����
//created: 2017/5/24 13:30pm
//Author: ȫ����
//mail: bcdass@naver.com


using namespace std;

class CurrentVoteListUI;
class VoteCollection;
class GroupCollection;


class CurrentVoteList
{
private:
	CurrentVoteListUI* currentVoteListUIPointer;
	VoteCollection* voteCollectionPointer;
public:
	CurrentVoteList(VoteCollection &voteCollection);
	~CurrentVoteList();

	void showVoteList(string* subject, int* items, string* startTime, string* endTime, string* belongsTo);

	CurrentVoteListUI* callCurrentVoteListUIStartInterface(CurrentVoteList &currentVoteList);
	CurrentVoteListUI* getCurrentVoteListUIPointer();
};

