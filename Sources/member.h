#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Member {
	string username, password;
};

void memberSave(const vector<Member>& members);
void memberJoin(vector<Member>& members);