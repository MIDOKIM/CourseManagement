#include "CourseManagement.h"
#include <string>
#include"database.h"
#include"adminPanel.h"
#include <QMessageBox>
#include"Home.h"
using namespace std;

CourseManagement::CourseManagement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Database::load();
}
void CourseManagement::on_pushButton_clicked() {
	string username = ui.lineEdit->text().toStdString();
	string password = ui.lineEdit_2->text().toStdString();
	auto user = Database::GetUserByUsername(username);
	if (user == nullptr)
	{
		QMessageBox msgBox;
    msgBox.setText("Wrong Username or Password");
    msgBox.setWindowTitle("Error");
    msgBox.exec();
		return;
	}
	if (user->Login(password))
	{
		//admin=1 student=0
		if (user->Role == 0) 
		{
		Home* nw = new Home(user);
		nw->show();
		this->hide();
		}
		else if (user->Role == 1)
		{
			adminPanel* nw = new adminPanel(user);
			nw->show();
			this->hide();
		}
	}
	else
	{
		QMessageBox msgBox;
    msgBox.setText("Wrong Username or Password");
    msgBox.setWindowTitle("Error");
    msgBox.exec();
	}

}
void CourseManagement::on_checkBox_stateChanged()
{
	(ui.checkBox->isChecked()) ? ui.lineEdit_2->setEchoMode(QLineEdit::Normal) : ui.lineEdit_2->setEchoMode(QLineEdit::Password);

}

