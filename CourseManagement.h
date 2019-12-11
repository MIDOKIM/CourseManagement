#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CourseManagement.h"

class CourseManagement : public QMainWindow
{
	Q_OBJECT

public:
	CourseManagement(QWidget *parent = Q_NULLPTR);

private:
	Ui::CourseManagementClass ui;
private slots:
	void on_pushButton_clicked();
	void on_checkBox_stateChanged();
};
