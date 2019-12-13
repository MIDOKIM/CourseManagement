#pragma once

#include <QWidget>
#include "ui_Home.h"

class Home : public QWidget
{
	Q_OBJECT
		
public:
	Home(User* user,QWidget *parent = Q_NULLPTR);
	~Home();
private:
	Ui::Home ui;

};
