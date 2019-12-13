#pragma once
#include <vector>
#include"Course.h"
#include"User.h"
#include "Student.h"
class Database
{
	public:
	static vector<Course*> Courses;
	static vector<User*> Users;
	static vector<Student*>Students;


	Database();
	~Database();
	static void load();
	static void Save();
	static vector<Course*> GetPreRequiredCourses(Course course);
	static Course* GetCourse(string courseID);
	static void AddStudent(int ID, int Year, vector<string> FCourses, vector<string> CinProgress);
	static void AddCourse(string id, string name, int num, int hours, vector<string> prc);
	static User* GetUserByID(int userID);
	static User* GetUserByUsername(string username);
	static Student* GetStudentByID(int userID);
	static Student* GetStudentByUsername(string username);
	static vector<User*> GetUsers(int Role);	
};

