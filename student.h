#pragma once
#include"User.h"
#include<vector>
class Course;
class Student : public User  
	
{
public:
	Student(int userID);
	int Academicyear;
	std::vector<string> FinishedCourses;
	std::vector<string> CoursesInProgress;
	bool CanTakeCourse(Course* c);
	bool HaveCourseInProgress(string courseid);
	bool HaveFinishedCourse(string courseid);
	vector<Course*> GetFinishedCourses();
	vector<Course*> GetCoursesInProgress();
	static vector<Student*> LoadStudents();
	static vector<string> GetStudentLines();
	Student();
	~Student();
};