#include "Course.h"
#include "CSVFile.h"
#include "Database.h"

vector<Student*> Course::GetStudents()
{
	vector<Student*> result;
	for (int i = 0; i < Database::Students.size(); i++)
	{
		Student* s = Database::Students[i];
		if (s->HaveCourseInProgress(Code))
			result.push_back(s);
	}
	return result;
}
vector<string> Course::GetCoursesLines()
{
	vector<string> result;
	string str = "";
	for (int i = 0; i < Database::Courses.size(); i++) {
		str+=Database::Courses[i]->Code + "," + Database::Courses[i]->Name +","+ to_string(Database::Courses[i]->Hours)+"," + to_string(Database::Courses[i]->MaxNumOfStudents) + ",";
		for (int j = 0; j < Database::Courses[i]->PreRequiredCourses.size(); j++) {
			str+=Database::Courses[i]->PreRequiredCourses[j] + ",";
		}str.pop_back();
		result.push_back(str);
	
	}
	
return result;
}
vector<Course*> Course::LoadCourses()
{
	vector<Course*> Result;
	CSVFile CoursesFile("courses.csv");
	auto lines = CoursesFile.Load();
	for (auto line : lines)
	{
		auto parsedLine = CSVFile::ParseLine(line);
		Course* course = new Course();
		course->Code = parsedLine[0];
		course->Name = parsedLine[1];
		course->Hours = stoi(parsedLine[2]);
		course->MaxNumOfStudents = stoi(parsedLine[3]);
		vector<string> PreCourses;
		for (int i = 4; i < parsedLine.size(); i++)
			PreCourses.push_back(parsedLine[i]);
		course->PreRequiredCourses = PreCourses;
		Result.push_back(course);
	}
	return Result;
}