#include "ControlAndCollection.h"
#include "ShowAllGroup.h"
#include "UserCollection.h"
#include "GroupCollection.h"
#include "CreateGroup.h"
#include "LeaveGroup.h"
#include "ShowJoinedGroup.h"
#include "VoteCollection.h"
#include "Join.h"
#include "JoinGroup.h"
#include "CreateVote.h"
#include"VoteFor.h"
#include "Login.h"
#include "Logout.h"
#include "Withdrwal.h"
#include "CurrentVoteList.h"
#include "PreVoteList.h"
#include "PostVoteList.h"

//Class: ControlAndCollection
//Description: ControlAndCollection ����. ��Ʈ�Ѱ� �ݷ��� ���������� Ŭ�����Դϴ�.
//created: 2017/5/30 21:00pm
//Author: ������
//mail: jang8018@naver.com



//����ƽ �ʱ�ȭ�Դϴ�.
ControlAndCollection* ControlAndCollection::instance = nullptr;


// Function : ControlAndCollection()
// Description: ControlAndCollection������ �Դϴ�.
// Parameters : none
// Return Value : void
//
// Created: 2017/6/01 18:00pm
// Author: ������
//
ControlAndCollection::ControlAndCollection()
{
	groupCollection = new GroupCollection();
	showAllGroup = new ShowAllGroup(*groupCollection);

	currentVoteCollection = new VoteCollection();
	postVoteCollection =	new VoteCollection();
	preVoteCollection =		new VoteCollection();


	groupCollection = new GroupCollection();
	userCollection = new UserCollection();

	showAllGroup = new ShowAllGroup(*groupCollection);
	createGroup = new CreateGroup(*groupCollection);
	showJoinedGroup = new ShowJoinedGroup;
	leaveGroup = new LeaveGroup;
	joinGroup = new JoinGroup(*groupCollection, *userCollection);

	createVote = new CreateVote(*postVoteCollection);
	voteFor = new VoteFor(*currentVoteCollection);

	currentVoteList = new CurrentVoteList(*currentVoteCollection);
	preVoteList = new PreVoteList(*preVoteCollection);
	postVoteList = new PostVoteList(*postVoteCollection);

	join = new Join(*userCollection);
	login = new Login(*userCollection);
	logout = new Logout(*userCollection);
	withdrwal = new Withdrwal(*userCollection);

}


ControlAndCollection::~ControlAndCollection()
{
}

// Function : ��Ʈ����Ʈ get�Լ�
// Description: private���ִ� ��Ʈ����Ʈ�� ��ȯ�մϴ�
// Parameters : none
// Return Value : ������ ��
//
// Created: 2017/6/01 18:30pm
// Author: ������
//
VoteCollection * ControlAndCollection::getCurrentVoteCollection()
{
	return currentVoteCollection;
}


VoteCollection * ControlAndCollection::getPostVoteCollection()
{
	return postVoteCollection;
}


VoteCollection * ControlAndCollection::getPreVoteCollection()
{
	return preVoteCollection;
}


UserCollection * ControlAndCollection::getUserCollection()
{
	return userCollection;
}


GroupCollection* ControlAndCollection::getGroupCollection()
{
	return groupCollection;
}


ShowAllGroup* ControlAndCollection::getShowAllGroup()
{
	return showAllGroup;
}


CreateGroup * ControlAndCollection::getCreateGroup()
{
	return createGroup;
}


ShowJoinedGroup * ControlAndCollection::getShowJoinedGroup()
{
	return showJoinedGroup;
}


LeaveGroup * ControlAndCollection::getLeaveGroup()
{
	return leaveGroup;
}


JoinGroup * ControlAndCollection::getJoinGroup()
{
	return joinGroup;
}


CreateVote * ControlAndCollection::getCreateVote()
{
	return createVote;
}


VoteFor * ControlAndCollection::getVoteFor()
{
	return voteFor;
}


CurrentVoteList * ControlAndCollection::getCurrentVoteList()
{
	return currentVoteList;
}


PreVoteList * ControlAndCollection::getPreVoteList()
{
	return preVoteList;
}


PostVoteList * ControlAndCollection::getPostVoteList()
{
	return postVoteList;
}

Join * ControlAndCollection::getJoin()
{
	return join;
}


Login * ControlAndCollection::getLogin()
{
	return login;
}


Logout * ControlAndCollection::getLogout()
{
	return logout;
}


Withdrwal * ControlAndCollection::getWithdrwal()
{
	return withdrwal;
}

// Function : GetInstance()
// Description: ControlAndCollection�̱��� �ν��Ͻ��� �����ϰų� ��ȯ�մϴ�.
// Parameters : none
// Return Value : ControlAndCollection *
//
// Created: 2017/5/30 21:15pm
// Author: ������
//
ControlAndCollection * ControlAndCollection::GetInstance()
{
	if (!instance) {
		instance = new ControlAndCollection();
	}
	return ControlAndCollection::instance;
}
