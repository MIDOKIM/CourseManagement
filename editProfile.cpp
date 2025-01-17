#include "editProfile.h"
#include"Home.h"
#include"database.h"
#include"qmessagebox.h"
editProfile::editProfile(Student* S,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	stud = S;
	load();
}
void editProfile::load()
{
	ui.lineEdit->setText(QString::fromStdString(stud->Name));
	ui.lineEdit_2->setText(QString::fromStdString(stud->Password));
	ui.lineEdit_3->setText(QString::number(stud->Academicyear));
}
editProfile::~editProfile()
{
}
void editProfile::on_pushButton_clicked()
{
	QMessageBox::StandardButton save;
	save = QMessageBox::question(this, "Save Info", "Save New Info?", QMessageBox::Yes | QMessageBox::No);
	if (save == QMessageBox::Yes)
	{
		stud->Name = ui.lineEdit->text().toStdString();
		stud->Password = ui.lineEdit_2->text().toStdString();
		stud->Academicyear = ui.lineEdit_3->text().toInt();
		Database::Save();
		
		this->close();
	}
}