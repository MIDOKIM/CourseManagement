#include <QMessageBox>
#include "adminPanel.h"
adminPanel::adminPanel(User* admin,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->admin = admin;
	LoadCrs();
	
}
void adminPanel::LoadCrs()
{
	auto itms = Course::CreateTree(Database::Courses);
	for (int i = 0; i < itms.size(); i++)
		ui.treeCrss->addTopLevelItem(itms[i]);
}
void adminPanel::item_Clicked(QTreeWidgetItem* item, int index)
{
	c = Database::GetCourse(item->data(0, Qt::UserRole).toString().toStdString());
	if (c == nullptr)
		return;
	ui.crsname->setText(QString::fromStdString(c->Name));
	ui.crscode->setText(QString::fromStdString(c->Code));
	ui.crshrs->setText(QString::number(c->Hours));
	ui.crsnumstd->setText(QString::number(c->MaxNumOfStudents));
}
adminPanel::~adminPanel()
{
}

void adminPanel::on_addsbtn_clicked()
{	
	QMessageBox msgBox;
	if (ui.newsname->text().isEmpty() || ui.newspw->text().isEmpty() || ui.newsrolecb->currentIndex()<0 || ui.newsun->text().isEmpty() || ui.newsyear->text().isEmpty())
	{
		msgBox.setWindowTitle("No Data Entered");
		msgBox.setText("Please Enter User Data");
		msgBox.exec();
		return;
	}
	if (ui.newsrolecb->currentIndex() == 1)
	{
		User::User(ui.newsname->text().toStdString(), ui.newsun->text().toStdString(), ui.newspw->text().toStdString(), ui.newsrolecb->currentIndex());//admin
		msgBox.setWindowTitle("User Added");
		msgBox.setText("Admin Added Successfuly");
		msgBox.exec();
	}
	else if (ui.newsrolecb->currentIndex() == 0)
	{
		vector<string> empty; // 3aiz azbot vector l string da
		Student::Student(ui.newsname->text().toStdString(), ui.newsun->text().toStdString(), ui.newspw->text().toStdString(), ui.newsyear->text().toInt(), empty, empty);//student
		msgBox.setWindowTitle("User Added");
		msgBox.setText("Student Added Successfuly");
		msgBox.exec();
	}
}
void adminPanel::on_addcbtn_clicked()
{
	QMessageBox msgBox;
	if(ui.newcname->text().isEmpty()||ui.newchrs->text().isEmpty()||ui.newcid->text().isEmpty()||ui.newcstd->text().isEmpty())
	{
		msgBox.setWindowTitle("No Data Entered");
		msgBox.setText("Please Enter Course Data");
		msgBox.exec();
		return;
	}
	vector<string> empty; //ana hna ba5od id l course bs ahna 3aizeno zi id l user byzed 1 kol mara ++ 3aiz azbot required courses
	Course::Course(ui.newcname->text().toStdString(), ui.newcid->text().toStdString(), ui.newcstd->text().toInt(), ui.newchrs->text().toInt(), empty);
	msgBox.setWindowTitle("Course Added");
	msgBox.setText("Course Added Successfuly");
	msgBox.exec();
}