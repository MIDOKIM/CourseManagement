#include "CourseManagement.h"
#include <QtWidgets/QApplication>
#include <student.h>
#include <GeneralTree.h>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	CourseManagement w;
	w.show();
	return a.exec();
}
