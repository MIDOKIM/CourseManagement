#include "CourseManagement.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	CourseManagement w;
	w.show();
	return a.exec();
}
