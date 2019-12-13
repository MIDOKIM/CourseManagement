#pragma once

#include <QWidget>
#include "User.h"
#include "ui_Home.h"
#include "student.h"
class User;

class Home : public QWidget
{
	Q_OBJECT
		
public:
	Home(User* user,QWidget *parent = Q_NULLPTR);
	User* user;
	Student* stud;
	~Home();
private:
	Ui::Home ui;
private slots:
	void on_viewmine_clicked();
	void on_viewall_clicked();
};
