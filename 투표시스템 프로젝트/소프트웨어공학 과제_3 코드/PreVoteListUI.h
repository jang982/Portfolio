#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

class PreVoteList;
class Group;
//Class: PreVoteListUI
//Description: PreVoteListUI 클래스
//created: 2017/5/24 11:00pm
//Author: 홍유남
//mail: bcdass@naver.com

class PreVoteListUI
{
private:
	PreVoteList* preVoteListPointer;
public:
	PreVoteListUI(PreVoteList &preVoteList);
	~PreVoteListUI();
	
	static PreVoteListUI* startInterface(PreVoteList& preVoteList);
	void confirmView(string* subject, int* items, string* startTime, string* endTime, string* belongsTo, int** result);
	void weekLater(string endTime);
};

