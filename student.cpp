#include "Student.h"
#include "database.h"
#include "CSVFile.h"
#include"Course.h"
Student::Student(int userID)
{
	auto user = Database::GetUserByID(userID);
	User::Name = user.Name;
	User::Username = user.Username;
	User::Password = user.Password;
	User::ID = user.ID;
	User::Role = user.Role;
}





bool Student::CanTakeCourse(Course c)
{
	for (int i = 0; i < c.PreRequiredCourses.size(); i++)
	{
		string courseid = c.PreRequiredCourses[i];
		if (HaveFinishedCourse(courseid) == false)
			return false;
	} 
	return true;
}

bool Student::HaveCourseInProgress(string courseid)
{
	for (auto course : CoursesInProgress)
	{
		if(course == courseid)
			return true;
	}
	return false;
}

bool Student::HaveFinishedCourse(string courseid)
{
	for (auto course : FinishedCourses)
	{
		if(course == courseid)
			return true;
	}
	return false;
}

vector<Student> Student::LoadStudents()
{
	vector<Student> result;
	CSVFile StudFile("Students.csv");
	auto lines = StudFile.Load();
	for (auto line : lines)
	{
		vector<string> parsedLine = CSVFile::ParseLine(line);
		Student std(stoi(parsedLine[0]));
		std.Academicyear = stoi(parsedLine[1]);
		auto numFinished = stoi(parsedLine[2]);
		auto numProgrs = stoi(parsedLine[3]);
		for(int i=4 ; i<= numFinished +3 ;i++)
		std.FinishedCourses.push_back(parsedLine[i]) ;
		for(int i = 4 + numFinished; i <= 4 + numFinished + numProgrs;i++)
		std.CoursesInProgress.push_back(parsedLine[i]);
		result.push_back(std);
	}
	
	return result;
}

vector<string> Student::GetStudentLines()//farah
{
	vector<string> result;
	for (int i = 0; i < Database::Students.size(); i++)
	{
		string s;
		Student student = Database::Students[i];

		s += student.ID + "," + to_string(student.Academicyear) + "," + to_string(student.FinishedCourses.size()) + "," + to_string(student.CoursesInProgress.size()) ;
		for (int i = 0; i < student.FinishedCourses.size(); i++)
		{
			s += ","+student.FinishedCourses[i];
			
		}
		for (int i = 0; i < student.CoursesInProgress.size(); i++)
		{

			s +=","+ student.CoursesInProgress[i];
		
		}
		result.push_back(s);
		s = "";
		
	}
	//ex:id,academicyear,number of finished courses,number of courses in progress,coursefinished1,coursefinished2,coursefinished3,....,courseinprogress1,courseinprogress2,....
	return result;
}

string Student::Studenttt(Student student)
{
	string l;
	for (int i = 0; i < student.CoursesInProgress.size(); i++)
	{
		
		l += student.CoursesInProgress[i];
		if (i != (student.CoursesInProgress.size() - 1))
			l += ",";
	}
	return l;
}

Student::Student()
{
}


Student::~Student()
{
}
