#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//Class: PostVoteListUI
//Description: PostVoteListUI Ŭ����
//created: 2017/5/24 12:50pm
//Author: ȫ����
//mail: bcdass@naver.com

class PostVoteList;
class Group;
class Timer;
class PostVoteListUI
{
private:
	PostVoteList* postVoteListPointer;
public:
	PostVoteListUI(PostVoteList &postVoteList);
	~PostVoteListUI();

	static PostVoteListUI* startInterface(PostVoteList& postVoteList);
	void confirmView(string* subject, int* items, string* start, string* endTime,string* belongsTo);
	void deleteMessage(Timer &time);
};

