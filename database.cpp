#include "Database.h"
#include "CSVFile.h"
vector<Course*> Database::Courses; // to prevent linking error
vector<User*> Database::Users; 
vector<Student*> Database::Students; 
Database::Database()
{
}
void Database::Save()
{
	CSVFile CoursesFile("courses.csv");
	CoursesFile.Save(Course::GetCoursesLines());
	CSVFile StudFile("Students.csv");
	StudFile.Save(Student::GetStudentLines());
	CSVFile UsersFile("users.csv");
	UsersFile.Save(User::GetUsersLines());
	
}
void Database::load() 
{
	Database:: Courses = Course::LoadCourses();
	Database::Users = User::LoadUsers();
	Database::Students = Student::LoadStudents();
}
Course* Database::GetCourse(string courseID)
{
	for (int i = 0; i < Courses.size(); i++)
	{
		if (courseID == Courses[i]->Code) {
			
			return Courses[i];
		}
	}
	return nullptr;
}
User* Database::GetUserByID(int userID)
{
	for (int i = 0; i < Users.size(); i++)
	{
		if (userID == Users[i]->ID)
			return Users[i];
	}
	return nullptr;
}
User* Database::GetUserByUsername(string username)
{
	for (int i = 0; i < Users.size(); i++)
	{
		if (username == Users[i]->Username)
			return Users[i];
	}
	return nullptr;
}
Student* Database::GetStudentByID(int userID)
{
	for (int i = 0; i < Students.size(); i++)
		if (userID == Students[i]->ID)
			return Students[i];
	return nullptr;
}
Student* Database::GetStudentByUsername(string username)
{
	for (int i = 0; i < Students.size(); i++)
		if (username == Students[i]->Username)
			return Students[i];
	return nullptr;
}
vector<User*> Database::GetUsers(int Role)
{
	vector<User*> Result;
	for (int i = 0; i < Users.size(); i++)
		if (Role == Users[i]->Role)
			Result.push_back(Users[i]);
	return Result;
	
}
vector<Course*> Database::GetPreRequiredCourses(Course course)
{

	vector<Course*> r;
	for (int i = 0; i < course.PreRequiredCourses.size(); i++) 
	{
		r.push_back(GetCourse(course.PreRequiredCourses[i]));
	}
	return r;
}
Database::~Database()
{
}
