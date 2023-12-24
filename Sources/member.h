#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

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
void memberDisplay();
void memberPrice(UserSession& session,map<int, int>& optionCounts);
void memberSearch(const vector<Member>& members, const string& memberTarget);
system_clock::time_point CalculateExpirationDate(int months);
void PrintExpirationDate(int optionChoice);