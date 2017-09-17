#pragma once

#include <iostream>
#include <string>
#include <list>

class User;

using namespace std;

class UserCollection {
private:
	list<User> userList;
	list<User>::iterator userListIterator;
public:
	list<User>::iterator findFirst();
	list<User>::iterator getNext(list<User>::iterator &inputIter);
	list<User>::iterator findEnd();
	list<User>::iterator findUser(string idOfUser);

	void addUser(string newName, string newPersonalNumber, string newAddress, string newID, string newPwd);

	void removeUser(string idOfUser);
	void setLoginUser(string idOfUser);
	void setLoginOffUser(string idOfUser);

	UserCollection();
	~UserCollection();
	
};

