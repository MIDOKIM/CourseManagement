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
	void Load();
private:
	Ui::Home ui;
private slots:
	void on_viewmine_clicked();
	void on_editdata_clicked();
	void on_logout_clicked();
	void on_rfrsh_clicked();
};
