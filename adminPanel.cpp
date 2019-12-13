#include "adminPanel.h"
#include "Course.h"
#include "Database.h"
#include "GeneralTree.h"

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
	aa(Database::Courses);
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
