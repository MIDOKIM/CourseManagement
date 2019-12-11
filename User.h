#pragma once
#include <string>
#include <vector>
using namespace std;
class User
{
	public:
	bool Login(string password);
	string Name;
	string Username;
	string Password;
	int ID;
	int Role;
	static vector<User> LoadUsers();
	static vector<string> GetUsersLines();
};

