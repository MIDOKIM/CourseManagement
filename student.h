#pragma once
#include"User.h"
#include<vector>
class Course;
class Student : public User  
	
{
public:
	Student(int userID);
	Student(string name, string username, string password, int academicyear, vector<string> finished,
	        vector<string> inprogress);
	int Academicyear;
	std::vector<string> FinishedCourses;
	std::vector<string> CoursesInProgress;
	bool CanTakeCourse(Course* c);
	bool HaveCourseInProgress(string courseid);
	bool HaveFinishedCourse(string courseid);
	void MoveCourseToFinished(string courseid);
	vector<Course*> GetFinishedCourses();
	vector<Course*> GetCoursesInProgress();
	static vector<Student*> LoadStudents();
	static vector<string> GetStudentLines();
	Student();
	~Student();
};