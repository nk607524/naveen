/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Main View for the Audit Management module.
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
#include "ui_AuditManagement_MainView.h"

class AuditManagement_Model;
class AuditManagement_MainView : public QMainWindow
{
	Q_OBJECT

public:
	AuditManagement_MainView(QSharedPointer<AuditManagement_Model> pAuditManagementModel, QWidget *parent = nullptr);
	~AuditManagement_MainView();

private:
	Ui::AuditManagement_MainViewClass ui;
};
