#pragma once
#include <string>
#include <iostream>
#include "User.h"
#include <vector>
#include "Course.h"

using namespace std;
class Admin : public User
{
public:
	void AddNewStudent();
	void AddNewCourse();
	void EnterCoursePrerequisite();
	vector<Course> ViewAvilableCourses();
	void EACD();
};


