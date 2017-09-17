#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

class PreVoteList;
class Group;
//Class: PreVoteListUI
//Description: PreVoteListUI Ŭ����
//created: 2017/5/24 11:00pm
//Author: ȫ����
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

