#pragma once

#include <QWidget>
#include "ui_adminPanel.h"
#include "User.h"


class User;

class adminPanel : public QWidget
{
	Q_OBJECT

public:
	adminPanel(User admin,QWidget *parent = Q_NULLPTR);
	~adminPanel();
 User admin;
	
private:
	Ui::adminPanel ui;
private slots:
	void on_pushButton1_Clicked();
	
};