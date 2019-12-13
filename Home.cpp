#include "Home.h"
#include <string>
#include"database.h"
#include <QMessageBox>
#include <iostream>
using namespace std;

Home::Home(User* user,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Home::~Home()
{
}
