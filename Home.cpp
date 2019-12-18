#include "Home.h"
#include <string>
#include"database.h"
#include <QMessageBox>
#include <iostream>
#include"ViewCourses.h"
#include"editProfile.h"
#include<CourseManagement.h>
using namespace std;

Home::Home(User* U, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->user = U;
	stud = new Student(user->ID);
	stud = Database::GetStudentByUsername(user->Username);
	Load();

}
void Home::Load()
{
	
	ui.label_5->setText(QString::fromStdString(user->Name));
	ui.label_6->setText(QString::number(stud->Academicyear));
	ui.label_7->setText(QString::number(stud->CoursesInProgress.size()));
	ui.label_8->setText(QString::number(stud->FinishedCourses.size()));
}
Home::~Home()
{
}

void Home::on_viewmine_clicked()
{
	ViewCourses* nw = new ViewCourses(stud);
	nw->show();
}
void Home::on_editdata_clicked()
{
	editProfile* nw = new editProfile(stud);
	nw->show();
	Load();
}
void Home::on_logout_clicked()
{
	user = stud = NULL;
	Home::close();
	auto bk = new CourseManagement();
	bk->show();
}