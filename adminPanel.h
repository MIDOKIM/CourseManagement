#pragma once

#include <QWidget>
#include "ui_adminPanel.h"
#include "User.h"
#include "Admin.h"
#include "adminPanel.h"
#include "Course.h"
#include "GeneralTree.h"
#include "Database.h"
#include "qmessagebox.h"

class User;

class adminPanel : public QWidget
{
	Q_OBJECT

public:
	adminPanel(User* admin,QWidget *parent = Q_NULLPTR);
	~adminPanel();
 User* admin;
 void LoadCrs(vector<Course*>,QTreeWidget*);
 Course* c;
 Student* S;
 QMessageBox Q;
 void Clear();
 void hidelabels();
 void showlabels();


private:
	Ui::adminPanel ui;
private slots:
	void on_addsbtn_clicked();
	void on_addcbtn_clicked();
	void itemClicked(QTreeWidgetItem* item, int index);
	void on_updatecrsinfo_clicked();
	QString getStuds(Course*);
	void on_getuserinfo_clicked();
	void on_updateuinfo_clicked();
	void on_courseisfinished_clicked();
};
