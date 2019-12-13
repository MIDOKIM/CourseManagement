
#include "adminPanel.h"
adminPanel::adminPanel(User* admin,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->admin = admin;
	
}

adminPanel::~adminPanel()
{
}

void adminPanel::on_pushButton1_Clicked()
{	
}

