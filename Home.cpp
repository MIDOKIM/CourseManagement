#include "Home.h"
#include <string>
#include"database.h"
#include <QMessageBox>
#include <iostream>
#include"ViewCourses.h"
using namespace std;

Home::Home(User* U,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->user = U;
	stud = new Student(user->ID);
	stud=Database::GetStudentByUsername(user->Username);
	ui.label_5->setText(QString::fromStdString(user->Name));
	ui.label_6->setText(QString::number(stud->Academicyear));
	ui.label_7->setText(QString::number(stud->CoursesInProgress.size()));
	ui.label_8->setText(QString::number(stud->FinishedCourses.size()));

}

Home::~Home()
{
}

void Home::on_viewall_clicked()
{
	ViewCourses* nw = new ViewCourses();
	nw->show();
}


void Home::on_viewmine_clicked()
{
	ViewCourses* nw = new ViewCourses(stud);
	nw->show();
}
