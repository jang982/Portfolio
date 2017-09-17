#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class User;


class User {
private:
	string userName;
	string userID;
	string personalNumber;
	string address;
	string userPwd;

	string joinedGroup;

	bool loginState;
	bool isLeader;

public:
	static User* createUser(string newName, string newPersonalNumber,string newAddress, string newID, string newPwd);
	void deleteUser();
	void setLoginOn();
	void setLoginOff();
	void setGroupLeader();
	void setJoinedGroup(string nameOfGroup);
	void withdrawGroup();

	User(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd);
	~User();
	string	getUserID();
	string getUserPwd();
	string	getJoinedGroup();
	string	getUserName();
	string getPersonalNumber();
	bool	getIsLeader();
};

