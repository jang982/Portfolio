#pragma once
#include <string>
#include <list>
//Class: PreVoteList
//Description: PreVoteList Ŭ����
//created: 2017/5/24 11:50pm
//Author: ȫ����
//mail: bcdass@naver.com

using namespace std;

class PreVoteListUI;
class VoteCollection;
class GroupCollection;

class PreVoteList
{
private:
	PreVoteListUI* preVoteListUIPointer;
	VoteCollection* voteCollectionPointer;
public:
	PreVoteList(VoteCollection &voteCollection);
	~PreVoteList();

	void showVoteList(string* subject, int* items, string* startTime, string* endTime,string* belongsTo,int** result);

	PreVoteListUI* callPreVoteListUIStartInterface(PreVoteList &PreVoteList);
	PreVoteListUI* getPreVoteListUIPointer();
	void		deleteVoteMessage(string endTime);
};

