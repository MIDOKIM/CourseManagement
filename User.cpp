#include "User.h"
#include "CSVFile.h"
#include "database.h"

User::User()
{
}


User::User(string name, string username, string password, int role)
{
	Name = name;
	Username = username;
	Password = password;
	Role=role;
	ID = Database::Users[Database::Users.size()-1]->ID +1;
	while (Database::GetUserByID(ID) != nullptr)
		ID++;
	Database::Users.push_back(this);
}

bool User::Login(string password)
{
	return Password == password;
}

vector<User*> User::LoadUsers()
{
	vector<User*> Result;
	CSVFile UsersFile("users.csv");
	auto lines = UsersFile.Load();
	for (auto line : lines)
	{
		auto parsedLine = CSVFile::ParseLine(line);
		User* u = new User();
		u->ID = stoi(parsedLine[0]);
		u->Username = parsedLine[1];
		u->Name = parsedLine[2];
		u->Password = parsedLine[3];
		u->Role = stoi(parsedLine[4]);
		Result.push_back(u);
	}
	return Result;
}

vector<string> User::GetUsersLines()//godzilla
{
	vector<string> V;
	for (int i = 0; i < Database::Users.size(); i++)
	{
		User* user = Database::Users[i];
		auto ST = to_string(user->ID) + "," + user->Username + "," + user->Name + "," + user->Password + "," +
			to_string(user->Role);	
		V.push_back(ST);
	}
	return V;
}
