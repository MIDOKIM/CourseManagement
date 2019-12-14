#pragma once

#include <QWidget>
#include "ui_editProfile.h"
#include "student.h"

class editProfile : public QWidget
{
	Q_OBJECT

public:
	editProfile(Student* S,QWidget *parent = Q_NULLPTR);
	~editProfile();
	Student* stud;
	void load();
private:
	Ui::editProfile ui;
private slots:
	void on_pushButton_clicked();
};
