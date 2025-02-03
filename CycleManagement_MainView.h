/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Main View for the Cycle Management module.
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
#include "ui_CycleManagement_MainView.h"

class CycleManagement_Model;
class CycleManagement_MainView : public QMainWindow
{
	Q_OBJECT

public:
	CycleManagement_MainView(QSharedPointer<CycleManagement_Model> pCycleManagementModel, QWidget *parent = nullptr);
	~CycleManagement_MainView();

private:
	Ui::CycleManagement_MainViewClass ui;
};
