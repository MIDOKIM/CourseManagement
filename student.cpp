#include "Student.h"
#include "database.h"
#include "CSVFile.h"
#include"Course.h"
Student::Student(int userID) : User(*Database::GetUserByID(userID))
{
	/*auto* user = Database::GetUserByID(userID);
	
	User::Name = user->Name;
	User::Username = user->Username;
	User::Password = user->Password;
	User::ID = user->ID;
	User::Role = user->Role;*/
}

Student::Student(string name, string username, string password, int academicyear, vector<string> finished,
	vector<string> inprogress) : User(name,username,password,0)
{
	Academicyear = academicyear;
	FinishedCourses = finished;
	CoursesInProgress = inprogress;
	Database::Students.push_back(this);
	Database::Save();
}

void Student::MoveCourseToFinished(string courseID)
{
	if (!HaveCourseInProgress(courseID))
		return;
	FinishedCourses.push_back(courseID);
	int index=0;
	for (auto course : CoursesInProgress)
	{
		if (course == courseID)
			break;
		index++;
	}
	CoursesInProgress.erase(CoursesInProgress.begin() + index);
}
bool Student::CanTakeCourse(Course* c)
{
	if (HaveFinishedCourse(c->Code) || HaveCourseInProgress(c->Code))
		return false;
	if (c->GetStudents().size() > c->MaxNumOfStudents)
		return false;
	for (int i = 0; i < c->PreRequiredCourses.size(); i++)
	{
		string courseid = c->PreRequiredCourses[i];
		if (!HaveFinishedCourse(courseid))
			return false;
		if (HaveCourseInProgress(courseid))
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
	for (int i = 0; i < FinishedCourses.size(); i++)
	{
		if(FinishedCourses[i] == courseid)
			return true;
	}
	return false;
}

vector<Course*> Student::GetFinishedCourses()
{
		vector<Course*> result;
		for (auto CID : FinishedCourses)
		{
			auto c = Database::GetCourse(CID);
			if (c != nullptr)
				result.push_back(c);
		}
	return result;
}

vector<Course*> Student::GetCoursesInProgress()
{
	vector<Course*> result;
		for (auto CID : CoursesInProgress)
		{
			auto c = Database::GetCourse(CID);
			if (c != nullptr)
				result.push_back(c);
		}
	return result;
}

vector<Student*> Student::LoadStudents()
{
	vector<Student*> result;
	CSVFile StudFile("Students.csv");
	auto lines = StudFile.Load();
	for (auto line : lines)
	{
		vector<string> parsedLine = CSVFile::ParseLine(line);
		Student* std = new Student(stoi(parsedLine[0]));
		std->Academicyear = stoi(parsedLine[1]);
		auto numFinished = stoi(parsedLine[2]);
		auto numProgrs = stoi(parsedLine[3]);
		for(int i=4 ; i<= numFinished +3 ;i++)
		std->FinishedCourses.push_back(parsedLine[i]) ;
		for(int i = 4 + numFinished; i < 4 + numFinished + numProgrs;i++)
		std->CoursesInProgress.push_back(parsedLine[i]);
		result.push_back(std);
	}
	
	return result;
}

vector<string> Student::GetStudentLines()//farah
{
	vector<string> result;
	for (int i = 0; i < Database::Students.size(); i++)
	{
		Student* student = Database::Students[i];
		User* user =Database::GetUserByID(student->ID);
		user->Name = student->Name;
		user->Username = student->Username;
		user->Password = student->Password;
		user->Role = student->Role;

		string s = to_string(student->ID) + "," + to_string(student->Academicyear) + "," +
			to_string(student->FinishedCourses.size()) + "," + to_string(student->CoursesInProgress.size());
		for (int i = 0; i < student->FinishedCourses.size(); i++)
			s += ","+student->FinishedCourses[i];
		for (int i = 0; i < student->CoursesInProgress.size(); i++)
			s +=","+ student->CoursesInProgress[i];		
		result.push_back(s);
		
	}
	//ex:id,academicyear,number of finished courses,number of courses in progress,coursefinished1,coursefinished2,coursefinished3,....,courseinprogress1,courseinprogress2,....
	return result;
}

Student::Student()
{
}


Student::~Student()
{
}
