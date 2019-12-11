#pragma once
#include <string>
#include <vector>
#include "Student.h"

using namespace std;
class Course
{
	public:
	string Name;
	string Code;
	int MaxNumOfStudents;
	int Hours;
	vector<string> PreRequiredCourses;
	vector<Student> GetStudents();
	static vector<string> GetCoursesLines();
	static vector<Course> LoadCourses();
};

