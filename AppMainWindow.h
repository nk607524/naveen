/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Main Window class for the application. It is dependant on Application_Model class.
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
#include "ui_AppMainWindow.h"
#include <QPointer>
#include <QSharedPointer>

class Application_Model;
class Model_MainView;
class CycleManagement_MainView;
class BCManagement_MainView;
class AuditManagement_MainView;

//Mainwindow class.
class AppMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	static QSharedPointer<AppMainWindow> getInstance();
private slots:	
	void on_actionNew_triggered(bool);
	void on_actionOpen_triggered(bool);
	void on_actionClose_triggered(bool);
	void on_actionSave_triggered(bool);
	void on_actionSaveAs_triggered(bool);
	void on_actionUser_Preferences_triggered(bool);
	void on_actionExit_triggered(bool);

	//Modules toolbar actions slots
	void on_actionModel_toggled(bool bChecked);
	void on_actionCycle_Management_toggled(bool bChecked);
	void on_actionBC_Management_toggled(bool bChecked);
	void on_actionAudit_Management_toggled(bool bChecked);
	
	void on_actionUser_Manual_triggered(bool);
	void on_actionAbout_triggered(bool);

protected:
	void closeEvent(QCloseEvent *event) override;

private:
	AppMainWindow(QWidget* parent = Q_NULLPTR);
	Ui::AppMainWindowClass ui;
	static QSharedPointer<AppMainWindow> ms_pAppMainWindow;

	//VNet Modules view objects
	QPointer<Model_MainView> m_pModel_MainView;
	QPointer<BCManagement_MainView> m_pBCManagement_MainView;
	QPointer<AuditManagement_MainView> m_pAuditManagement_MainView;
	QPointer<CycleManagement_MainView> m_pCycleManagement_MainView;
	
	QSharedPointer<Application_Model>m_pApplication_Model;
	
	void initProjectViews();
	void clearViews();
	void enableActions(bool bEnable);
};
