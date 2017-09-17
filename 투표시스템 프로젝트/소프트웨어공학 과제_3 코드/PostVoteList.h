#pragma once
#include <string>
#include <list>

//Class: PostVoteList
//Description: PostVoteList 클래스
//created: 2017/5/24 12:50pm
//Author: 홍유남
//mail: bcdass@naver.com

using namespace std;

class PostVoteListUI;
class VoteCollection;
class GroupCollection;

class PostVoteList
{
private:
	PostVoteListUI* postVoteListUIPointer;
	VoteCollection* voteCollectionPointer;
public:
	PostVoteList(VoteCollection &voteCollection);
	~PostVoteList();

	void showVoteList(string* subject, int* items, string* startTime, string* endTime, string* belongsTo);

	PostVoteListUI* callPostVoteListUIStartInterface(PostVoteList &PostVoteList);
	PostVoteListUI* getPostVoteListUIPointer();
};

