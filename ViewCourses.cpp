#include "ViewCourses.h"
#include "Course.h"
#include"database.h"
#include"qmessagebox.h"

ViewCourses::ViewCourses(Student* S,QWidget* parent)
	: QWidget(parent)
{
	stud = S;
	c=nullptr;
	ui.setupUi(this);
	ui.rgstrbtn->hide();
	RadioButton_Clicked();
	ui.lbl_Code->hide();
	ui.lbl_Hours->hide();
	ui.lbl_MaxNum->hide();
	ui.lbl_Name->hide();
}
ViewCourses::~ViewCourses()
{
}

void ViewCourses::RadioButton_Clicked()
{
	ui.rgstrbtn->hide();
	ui.treeWidget->clear();
	bool Fulltree = true;
	vector<Course*> ToDisplay;
	if(ui.rad_All->isChecked())
		ToDisplay = Database::Courses;
	else if (ui.rad_Finished->isChecked())
		ToDisplay = stud->GetFinishedCourses();
	else if (ui.rad_Progrss->isChecked())
	{
		ToDisplay = stud->GetCoursesInProgress();
		Fulltree = false;
	}
	else if (ui.radAllowed->isChecked())
	{
		ui.rgstrbtn->show();
		for (int i = 0; i < Database::Courses.size(); i++)
		{
			if (stud->CanTakeCourse(Database::Courses[i]))
				ToDisplay.push_back(Database::Courses[i]);
		}
	}
	auto itms = Course::CreateTree(ToDisplay,Fulltree);
		for (int i = 0; i < itms.size(); i++)
			ui.treeWidget->addTopLevelItem(itms[i]);
}

void ViewCourses::Widget_Item_Clicked(QTreeWidgetItem* item, int index)
{
	if (ui.lbl_Code->isHidden())
	{
		ui.lbl_Code->show();
		ui.lbl_Hours->show();
		ui.lbl_MaxNum->show();
		ui.lbl_Name->show();
	}
	c= Database::GetCourse(item->data(0,Qt::UserRole).toString().toStdString());
	if (c == nullptr)
		return;
		ui.lbl_Name->setText("Course Name: \n"+QString::fromStdString(c->Name));
		ui.lbl_Code->setText("Course Id: \n" + QString::fromStdString(c->Code));
		ui.lbl_Hours->setText("Course MaxHourse: \n" + QString::number(c->Hours));
		ui.lbl_MaxNum->setText("Course MaxNumOfStuds: \n" + QString::number(c->MaxNumOfStudents));
}

void ViewCourses::on_rgstrbtn_clicked()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Register Course", "Are you sure you wawnt to register for the selected course?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
		if (c == nullptr)
			return;
		if (stud->CanTakeCourse(c))
			stud->CoursesInProgress.push_back(c->Code);
		ViewCourses::RadioButton_Clicked();
		Database::Save();
	}
}
