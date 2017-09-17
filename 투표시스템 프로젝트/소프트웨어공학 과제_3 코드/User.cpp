#include "User.h"

//Class: User
//Description: User 구현
//created: 2017/5/27 21:00pm
//Author: 장현석
//mail: jang8018@naver.com


User::User(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	userName = newName;
	personalNumber = newPersonalNumber;
	userID = newID;
	address = newAddress;
	userPwd = newPwd;

	joinedGroup = "none";
	isLeader = false;
	loginState = false;
}


User::~User()
{
}

User* User::createUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd)
{
	User* newUser = new User(newName,newPersonalNumber,newAddress,newID,newPwd);
	return newUser;
};

void User::deleteUser() 
{
	User::~User();
};

void User::setLoginOn() 
{
	loginState = true;
};

void User::setLoginOff() 
{
	loginState = false;
};
void User::setGroupLeader() 
{
	isLeader = true;
}

void User::setJoinedGroup(string nameOfGroup)
{
	joinedGroup = nameOfGroup;
};
void User::withdrawGroup() 
{
	joinedGroup = "none";
};

string User::getJoinedGroup() 
{
	return joinedGroup;
};

string User::getUserID()
{
	return userID;
}
string User::getUserPwd()
{
	return userPwd;
}
string User::getUserName()
{
	return userName;
}

string User::getPersonalNumber()
{
	return personalNumber;
}

bool User::getIsLeader()
{
	return isLeader;
}