#pragma once
#define USERGROUP_H
#include <iostream>
#include <string>
#include <list>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


//Class: User
//Description: user를 위한 클래스
//created: 2017/5/24 11:00am
//Author: 김윤영
//mail: kyy01114@hanmail.net

//유저

//class User {
//private:
//	string userName;
//	string userID;
//	string personalNumber;
//	string address;
//	string userPwd;
//
//	string joinedGroup;
//
//	bool loginState;
//	bool IsLeader;
//
//public:
//	void createUser();
//	void deleteUser();
//	
//	void setLoginOn();
//	void setLoginOff();
//	void setGroupLeader();
//	void setJoinedGroup();
//	void withdrawGroup();
//
//	string getJoinedGroup();
//};

//유저 콜렉션

//class UserCollection {
//private:
//public:
//	void setMember();
//	void removeMeber();
//};


//그룹

////Class: Group
////Description: group을 위한 클래스
////created: 2017/5/24 11:00am
////Author: 김윤영
////mail: kyy01114@hanmail.net
//class Group {
//private:
//	string			groupName;
//	UserCollection* ownedUserCollection;
//public:
//	Group(string nameOfGroup);
//	~Group();
//
//	static Group*	createGroup(string nameOfGroup);
//	void			deleteGroup();
//
//	string			getGroupName();	
//	void			setGroupName(string inputName);
//};


//class VoteCollection {
//private:
//public:
//};
//Class: Vote
//Description: vote를 위한 클래스
//created: 2017/5/24 11:00am
//Author: 김윤영
//mail: kyy01114@hanmail.net
//class Vote {
//private:
//	int voidID;
//	string subject;
//	int items[10];
//	string startTime;
//	string endTime;
//public:
//	void showVoteDetails();

//};
