#include "CourseManagement.h"
#include <string>
#include"database.h"
#include"adminPanel.h"
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
	if (user == NULL)
		return;
	if (user->Login(password))
	{
	adminPanel* nw = new adminPanel();
	nw->show();
	this->hide();
	}
	else
		return;

}

void CourseManagement::on_checkBox_stateChanged()
{
	(ui.checkBox->isChecked()) ? ui.lineEdit_2->setEchoMode(QLineEdit::Normal) : ui.lineEdit_2->setEchoMode(QLineEdit::Password);

}

