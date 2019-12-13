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
	QString* ss = new QString("sssss");
	QStringList* lst = new QStringList();
	lst->push_back(*ss);
	QTreeWidgetItem* a = new QTreeWidgetItem(*lst);
	a->addChild(new QTreeWidgetItem(*lst));
	ui.treeWidget->addTopLevelItem(a);

}
