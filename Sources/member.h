#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Member {
	string username, password;
};

struct UserSession {
	string username;
	bool login;
};

void memberSave(const vector<Member>& members);
void memberJoin(vector<Member>& members);
void memberLogin(const vector<Member>& members, UserSession& session);