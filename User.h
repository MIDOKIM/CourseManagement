#pragma once
#include <string>
#include <vector>
using namespace std;
class User
{
	public:
	User();
	User(string name,string username,string password,int role);
	bool Login(string password);
	string Name;
	string Username;
	string Password;
	int ID;
	int Role;
	static vector<User*> LoadUsers();
	static vector<string> GetUsersLines();
};

