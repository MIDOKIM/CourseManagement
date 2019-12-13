
#include "adminPanel.h"
adminPanel::adminPanel(User* admin,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->admin = admin;

	auto itms=Course::CreateTree(Database::Courses);
	for (int i = 0; i < itms.size(); i++)
	ui.treeWidget->addTopLevelItem(itms[i]);
}

adminPanel::~adminPanel()
{
}

void adminPanel::on_treeWidget_ItemClicked()
{

	int x=ui.treeWidget->selectedItems().count();
	ui.label->setText(QString::number(x));
}

void adminPanel::on_pushButton1_Clicked()
{	
}

