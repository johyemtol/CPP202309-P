#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Member {
	string username, password;
};

void memberSave();
void memberJoin();