#include "CourseManagement.h"
#include <string>
using namespace std;

CourseManagement::CourseManagement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void CourseManagement::on_pushButton_clicked() {
	string username = ui.lineEdit->text().toStdString();
	string password = ui.lineEdit_2->text().toStdString();
	//Test* nw = new Test();
	//nw->show();
	//this->hide();
}

void CourseManagement::on_checkBox_stateChanged()
{
	(ui.checkBox->isChecked()) ? ui.lineEdit_2->setEchoMode(QLineEdit::Normal) : ui.lineEdit_2->setEchoMode(QLineEdit::Password);

}

