#pragma once

#include <QWidget>
#include "ui_ViewCourses.h"
#include"student.h"
class ViewCourses : public QWidget
{
	Q_OBJECT

public:
	ViewCourses(QWidget *parent = Q_NULLPTR);
	ViewCourses(Student* S,QWidget* parent = Q_NULLPTR);
	~ViewCourses();
	Student* stud;

private:
	Ui::ViewCourses ui;
private slots:
	void on_Item_Clicked();
	void RadioButton_Clicked();
};
