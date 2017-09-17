#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

//Class: currentVoteListUI
//Description: currentVoteListUI 클래스
//created: 2017/5/24 13:30pm
//Author: 홍유남
//mail: bcdass@naver.com


class CurrentVoteList;
class Group;

class CurrentVoteListUI
{
private:
	CurrentVoteList* currentVoteListPointer;
public:
	CurrentVoteListUI(CurrentVoteList &currentVoteList);
	~CurrentVoteListUI();

	static CurrentVoteListUI* startInterface(CurrentVoteList& currentVoteList);
	void confirmView(string* subject, int* items, string* startTime, string* endTime, string* belongsTo);
};

