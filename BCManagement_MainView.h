/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Main View for the BC Management module.
 *
 * @Copyright     :	Copyright (c) 2000-2001 Honeywell Inc.
 * 					All rights reserved. This work contains trade secrets
 *					and confidential materials of Honeywell Inc., and its
 *					use of disclosure in whole or in part without express
 *  				written permission of Honeywell Inc. is prohibited.
 *
 * @Company		  : Honeywell Technology Solutions.
 * @author	      : Gaurav Banda
 * @Version	      : 10.0
 *
 * @Modification History:
 * @By :
 * @On :
 * @Reason :
 *************************************************************************/
#pragma once

#include <QMainWindow>
#include "ui_BCManagement_MainView.h"

class BCManagement_Model;
class BCManagement_MainView : public QMainWindow
{
	Q_OBJECT

public:
	BCManagement_MainView(QSharedPointer<BCManagement_Model> pBCManagementModel, QWidget *parent = nullptr);
	~BCManagement_MainView();

private:
	Ui::BCManagement_MainViewClass ui;
};
