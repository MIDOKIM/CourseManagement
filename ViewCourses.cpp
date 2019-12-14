#include "ViewCourses.h"
#include "Course.h"
#include"database.h"

ViewCourses::ViewCourses(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
ViewCourses::ViewCourses(Student* S,QWidget* parent)
	: QWidget(parent)
{
	stud = S;
	ui.setupUi(this);
	RadioButton_Clicked();
}
ViewCourses::~ViewCourses()
{
}

void ViewCourses::RadioButton_Clicked()
{
	ui.treeWidget->clear();
	vector<Course*> ToDisplay;
	if(ui.rad_All->isChecked())
		ToDisplay = Database::Courses;
	else if (ui.rad_Finished->isChecked())
		ToDisplay = stud->GetFinishedCourses();
	else if (ui.rad_Progrss->isChecked())
		ToDisplay = stud->GetCoursesInProgress();
	else if (ui.radAllowed->isChecked())
	{
		for (int i = 0; i < Database::Courses.size(); i++)
		{
			if (stud->CanTakeCourse(Database::Courses[i]))
				ToDisplay.push_back(Database::Courses[i]);
		}
	}
	auto itms = Course::CreateTree(ToDisplay);
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
}

void ViewCourses::Widget_Item_Clicked(QTreeWidgetItem* item, int index)
{
	Course* c = Database::GetCourse(item->data(0,Qt::UserRole).toString().toStdString());
	if (c == nullptr)
		return;
		ui.lbl_Name->setText(QString::fromStdString(c->Name));
		ui.lbl_Code->setText(QString::fromStdString(c->Code));
		ui.lbl_Hours->setText(QString::number(c->Hours));
		ui.lbl_MaxNum->setText(QString::number(c->MaxNumOfStudents));

}
