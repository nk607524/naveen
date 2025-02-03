#pragma once

#include <QWidget>
#include "ui_DesignToolBarWidgets.h"

class DesignToolBarWidgets : public QWidget
{
	Q_OBJECT

public:
	DesignToolBarWidgets(QWidget *parent = nullptr);
	~DesignToolBarWidgets();
private slots:
	void updateActiveSubSystem();
private:
	Ui::DesignToolBarWidgetsClass ui;
};
