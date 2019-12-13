#pragma once

#include <QObject>

class EditStudent : public QObject
{
	Q_OBJECT

public:
	EditStudent(QObject *parent);
	~EditStudent();
};
