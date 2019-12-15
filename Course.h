#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include <qtreewidget.h>
using namespace std;
class Course
{
	public:
	Course();
	Course(string name,string code,int maxnum,int hours,vector<string> prerequired);
	string Name;
	string Code;
	int MaxNumOfStudents;
	int Hours;
	vector<string> PreRequiredCourses;
	vector<Student*> GetStudents();
	static vector<string> GetCoursesLines();
	static vector<Course*> LoadCourses();
	static vector<QTreeWidgetItem*> CreateTree(vector<Course*> Courses);
	
};

