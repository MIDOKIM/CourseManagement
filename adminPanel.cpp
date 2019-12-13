
#include <QMessageBox>
#include "adminPanel.h"

adminPanel::adminPanel(User* admin,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->admin = admin;
	aa(Database::Courses);

}

adminPanel::~adminPanel()
{
}

void adminPanel::on_pushButton1_Clicked()
{
}
QTreeWidgetItem* createitem(Node* n)
{
		QTreeWidgetItem* item = new QTreeWidgetItem();
		item->setText(0,QString::fromStdString(Database::GetCourse(n->Value)->Name));
		for (auto element : n->Childs)
		{
			auto widgetitem = createitem(element);
			item->addChild(widgetitem);
		}
	return  item;
}

void adminPanel::aa(vector<Course*> courses)
{
	GeneralTree tree;
	for (auto  c : courses)
	{
			for (auto element : c->PreRequiredCourses)
			{
				tree.AddChild(c->Code,element);
			}
	}

	for (auto c : tree.Nodes)
	{
		ui.treeWidget->addTopLevelItem(createitem(c));
	}
	
}
