#pragma once

#include <QWidget>
#include "ui_adminPanel.h"

class adminPanel : public QWidget
{
	Q_OBJECT

public:
	adminPanel(QWidget *parent = Q_NULLPTR);
	~adminPanel();
	
private:
	Ui::adminPanel ui;
private slots:
	void on_pushButton1_Clicked();
	
};
