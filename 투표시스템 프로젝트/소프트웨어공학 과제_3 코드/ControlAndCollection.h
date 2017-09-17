#pragma once
#include <iostream>


//Class: ControlAndCollection 
//Description: ControlAndCollection ���. ��Ʈ�Ѱ� �ݷ��� ���������� Ŭ�����Դϴ�.
//created: 2017/5/30 20:50pm
//Author: ������
//mail: jang8018@naver.com


class UserCollection;
class GroupCollection;
class VoteCollection;

class ShowAllGroup;
class CreateGroup;
class ShowJoinedGroup;
class LeaveGroup;
class JoinGroup;

class CreateVote;
class VoteFor;

class CurrentVoteList;
class PreVoteList;
class PostVoteList;

class Join;
class Login;
class Logout;
class Withdrwal;


using namespace std;


class ControlAndCollection
{	
private:
	VoteCollection *currentVoteCollection;
	VoteCollection *postVoteCollection;
	VoteCollection *preVoteCollection;

	UserCollection	*userCollection;
	GroupCollection *groupCollection;

	ShowAllGroup	*showAllGroup;
	CreateGroup *createGroup;
	ShowJoinedGroup		*showJoinedGroup;
	LeaveGroup			*leaveGroup;
	JoinGroup			*joinGroup;

	CreateVote *createVote;
	VoteFor *voteFor;

	CurrentVoteList *currentVoteList;
	PreVoteList *preVoteList;
	PostVoteList *postVoteList;

	Join *join;
	Login *login;
	Logout *logout;
	Withdrwal *withdrwal;

	ControlAndCollection();
	ControlAndCollection(const ControlAndCollection& other);
	~ControlAndCollection();

	static ControlAndCollection* instance;
public:

	VoteCollection *getCurrentVoteCollection();
	VoteCollection *getPostVoteCollection();
	VoteCollection *getPreVoteCollection();

	UserCollection	*getUserCollection();
	GroupCollection* getGroupCollection();

	ShowAllGroup* getShowAllGroup();
	CreateGroup *getCreateGroup();
	ShowJoinedGroup		*getShowJoinedGroup();
	LeaveGroup			*getLeaveGroup();
	JoinGroup			*getJoinGroup();

	CreateVote *getCreateVote();
	VoteFor *getVoteFor();

	CurrentVoteList *getCurrentVoteList();
	PreVoteList *getPreVoteList();
	PostVoteList *getPostVoteList();

	Join *getJoin();
	Login *getLogin();
	Logout *getLogout();
	Withdrwal *getWithdrwal();

	static ControlAndCollection* GetInstance();

};

