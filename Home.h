#pragma once

#include <QWidget>
#include "User.h"
#include "ui_Home.h"
class User;

class Home : public QWidget
{
	Q_OBJECT
		
public:
	Home(User* user,QWidget *parent = Q_NULLPTR);
	User* user;
	~Home();
private:
	Ui::Home ui;

};
