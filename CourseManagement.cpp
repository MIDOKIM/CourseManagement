#include "CourseManagement.h"
#include <string>
#include"database.h"
#include"adminPanel.h"
#include <QMessageBox>
#include"Home.h"
#include"qstylefactory.h"
#include <QtGui/QIcon>

using namespace std;

CourseManagement::CourseManagement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	///// Fusion Style
	QApplication::setStyle(QStyleFactory::create("Fusion"));
	// set Fusion To datk
	{
		QPalette darkPalette;
		darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
		darkPalette.setColor(QPalette::WindowText, Qt::white);
		darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(127, 127, 127));
		darkPalette.setColor(QPalette::Base, QColor(42, 42, 42));
		darkPalette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
		darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
		darkPalette.setColor(QPalette::ToolTipText, Qt::white);
		darkPalette.setColor(QPalette::Text, Qt::white);
		darkPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
		darkPalette.setColor(QPalette::Dark, QColor(35, 35, 35));
		darkPalette.setColor(QPalette::Shadow, QColor(20, 20, 20));
		darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
		darkPalette.setColor(QPalette::ButtonText, Qt::white);
		darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
		darkPalette.setColor(QPalette::BrightText, Qt::red);
		darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
		darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
		darkPalette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
		darkPalette.setColor(QPalette::HighlightedText, Qt::white);
		darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));

		QApplication::setPalette(darkPalette);
	}
	QIcon icon("myicon.png");
	QApplication::setWindowIcon(icon);
	Database::load();
}
void CourseManagement::on_pushButton_clicked() {
	if (ui.lineEdit->text().isEmpty()||ui.lineEdit_2->text().isEmpty())
	{
		msgBox.setText("Please Enter account data");
		msgBox.setWindowTitle("Data is missing");
		msgBox.exec();
	}
	string username = ui.lineEdit->text().toStdString();
	string password = ui.lineEdit_2->text().toStdString();
	auto user = Database::GetUserByUsername(username);
	if (user == nullptr)
	{
    msgBox.setText("Wrong Username or Password");
    msgBox.setWindowTitle("Worng data");
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
