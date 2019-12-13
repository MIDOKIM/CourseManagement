#include "ViewCourses.h"
#include "Course.h"
#include"database.h"
ViewCourses::ViewCourses(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.checkBox->hide();
	ui.checkBox_1->show();
	ui.treeWidget->clear();
	auto itms = Course::CreateTree(Database::Courses);
	for (int i = 0; i < itms.size(); i++)
		ui.treeWidget->addTopLevelItem(itms[i]);
}
ViewCourses::ViewCourses(Student* S,QWidget* parent)
	: QWidget(parent)
{
	stud = S;
	ui.setupUi(this);
	ui.checkBox->show();
	ui.checkBox_1->hide();
	ui.treeWidget->clear();
		auto itms = Course::CreateTree(stud->GetCoursesInProgress());
	for (int i = 0; i < itms.size(); i++)
		ui.treeWidget->addTopLevelItem(itms[i]);
	 itms = Course::CreateTree(stud->GetFinishedCourses());
	for (int i = 0; i < itms.size(); i++)
		ui.treeWidget->addTopLevelItem(itms[i]);
}
ViewCourses::~ViewCourses()
{
}

void ViewCourses::on_checkBox_stateChanged()
{
	if (ui.checkBox->isChecked())
	{
		ui.treeWidget->clear();
		auto itms = Course::CreateTree(stud->GetCoursesInProgress());
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
	}
	else if (!ui.checkBox->isChecked())
	{
		ui.treeWidget->clear();
		auto itms = Course::CreateTree(stud->GetCoursesInProgress());
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
		itms = Course::CreateTree(stud->GetFinishedCourses());
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
	}
	
}
void ViewCourses::on_checkBox_1_stateChanged()
{
	if (ui.checkBox->isChecked())
	{
		ui.treeWidget->clear();
		auto itms = Course::CreateTree(Database::Courses);
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
	}
	else if (!ui.checkBox->isChecked())
	{
		ui.treeWidget->clear();
		vector<Course*> result;
		for (int i = 0; i < Database::Courses.size(); i++)
		{
			if (stud->CanTakeCourse(Database::Courses[i]))
				result.push_back(Database::Courses[i]);
		}
		auto itms = Course::CreateTree(result);
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
	}

}

void ViewCourses::on_Item_Clicked()
{
}