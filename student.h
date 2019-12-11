#pragma once
#include"User.h"
#include<vector>
class Course;
class Student : public User  
	
{
public:
	Student(int userID);
	int Academicyear;
	vector<string> FinishedCourses,CoursesInProgress;
	bool CanTakeCourse(Course c);
	bool HaveCourseInProgress(string courseid);
	bool HaveFinishedCourse(string courseid);
	static vector<Student> LoadStudents();
	static vector<string> GetStudentLines();
	static string Studentt(Student student);
	static string Studenttt(Student student);
	Student();
	~Student();
};