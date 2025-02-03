#include "AppMainWindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>

//Modules
#include "Model_MainView.h"
#include "CycleManagement_MainView.h"
#include "BCManagement_MainView.h"
#include "AuditManagement_MainView.h"

#include "Application_Model.h"
#include "Project_Model.h"
#include "CycleManagement_Model.h"
#include "BCManagement_Model.h"
#include "AuditManagement_Model.h"

constexpr auto LANDING_PAGEINDEX = 0;
constexpr auto MODEL_MAINVIEW_PAGEINDEX = 1;
constexpr auto CYCLEMANAGEMENT_MAINVIEW_PAGEINDEX = 2;
constexpr auto BCMANAGEMENT_MAINVIEW_PAGEINDEX = 3;
constexpr auto AUDITMANAGEMENT_MAINVIEW_PAGEINDEX = 4;

QSharedPointer<AppMainWindow> AppMainWindow::ms_pAppMainWindow(NULL);
AppMainWindow::AppMainWindow(QWidget *parent)
	: QMainWindow(parent), m_pModel_MainView(NULL), m_pBCManagement_MainView(NULL), m_pAuditManagement_MainView(NULL),
	m_pCycleManagement_MainView(NULL), m_pApplication_Model(NULL)
{
	ui.setupUi(this);

	//Add modules toolbar in an action group for exclusiveness
	QActionGroup* l_pActionGrpModules = new QActionGroup(this);
	ui.actionModel->setActionGroup(l_pActionGrpModules);
	ui.actionCycle_Management->setActionGroup(l_pActionGrpModules);
	ui.actionBC_Management->setActionGroup(l_pActionGrpModules);
	ui.actionAudit_Management->setActionGroup(l_pActionGrpModules);
	l_pActionGrpModules->setExclusive(true);

	ui.actionExit->setShortcuts(QKeySequence::Quit);

	//Disable toolbar items.
	enableActions(false);

	//Create application model
	m_pApplication_Model = Application_Model::getInstance();
}
QSharedPointer<AppMainWindow> AppMainWindow::getInstance()
{
	if (ms_pAppMainWindow.isNull())
		ms_pAppMainWindow = QSharedPointer<AppMainWindow>(new AppMainWindow(), &AppMainWindow::deleteLater);
	return ms_pAppMainWindow;
}

void AppMainWindow::on_actionNew_triggered(bool bChecked)
{
	if (!m_pApplication_Model.isNull())
	{
		on_actionClose_triggered(bChecked);

		QApplication::setOverrideCursor(Qt::WaitCursor);
		QString l_strErrorMessage;
		bool l_bSuccess = m_pApplication_Model->newProject(l_strErrorMessage);
		if (!l_bSuccess)
		{
			QMessageBox::critical(this, "New Project Error!", l_strErrorMessage);
		}
		else
		{
			initProjectViews();
		}
		QApplication::restoreOverrideCursor();
	}
}
void AppMainWindow::on_actionOpen_triggered(bool bChecked)
{
	if (m_pApplication_Model)
	{
		QString l_strFileName = QFileDialog::getOpenFileName(this, tr("Open project File"),
			QString(), tr("VNet Project (*.vnp)"));

		if (!l_strFileName.isEmpty())
		{
			on_actionClose_triggered(bChecked);

			QApplication::setOverrideCursor(Qt::WaitCursor);
			QString l_strErrorMessage;
			bool l_bSuccess = m_pApplication_Model->openProject(l_strFileName, l_strErrorMessage);
			if (!l_bSuccess)
			{
				QMessageBox::critical(this, "Open Project Error!", l_strErrorMessage);
			}
			else
			{
				initProjectViews();
			}
			QApplication::restoreOverrideCursor();
		}
	}
}
void AppMainWindow::on_actionClose_triggered(bool bChecked)
{
	if (m_pApplication_Model)
	{
		QSharedPointer<Project_Model> l_pProjectModel = m_pApplication_Model->getProjectModel();
		if (!l_pProjectModel.isNull() && l_pProjectModel->isDirty())
		{
			QMessageBox::StandardButton l_enReply = QMessageBox::question(this, "Unsaved data",
				"Do you want to save the data ?",
				QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
			switch (l_enReply)
			{
			case QMessageBox::Yes:
			{
				on_actionSave_triggered(true);
			}
			break;
			case QMessageBox::Cancel:
			{
				return;
			}
			break;
			}
		}
		m_pApplication_Model->closeProject();
	}
	clearViews();
	enableActions(false);
}
void AppMainWindow::on_actionSave_triggered(bool bChecked)
{
	if (m_pApplication_Model)
	{
		QSharedPointer<Project_Model> l_pProjectModel = m_pApplication_Model->getProjectModel();
		if (!l_pProjectModel.isNull())
		{
			QString l_strFileName = l_pProjectModel->getFileName();
			if (l_strFileName != "")
			{
				if (!l_pProjectModel.isNull() && l_pProjectModel->isDirty())
				{
					QString l_strErrorMessage;
					if (l_pProjectModel->save(l_strErrorMessage))
					{
						ui.statusBar_mainWindow->showMessage("Project file " + l_strFileName + " saved.");
					}
					else
					{
						QMessageBox::critical(this, "Save Project Error!", l_strErrorMessage);
					}
				}
			}
			else
			{
				on_actionSaveAs_triggered(bChecked);
			}
		}
	}
}
void AppMainWindow::on_actionSaveAs_triggered(bool bChecked)
{
	if (!m_pApplication_Model.isNull())
	{
		QSharedPointer<Project_Model> l_pProjectModel = m_pApplication_Model->getProjectModel();
		if (!l_pProjectModel.isNull())
		{
			QString l_strFileName = QFileDialog::getSaveFileName(this, tr("Save Project File"),
				QDir::homePath(), tr("VNet Project (*.vnp)"));

			if (l_strFileName != "")
			{
				if (!l_pProjectModel.isNull() && l_pProjectModel->isDirty())
				{
					QString l_strErrorMessage;
					if (l_pProjectModel->saveAs(l_strFileName, l_strErrorMessage))
					{
						ui.statusBar_mainWindow->showMessage("Project file " + l_strFileName + " saved.");
					}
					else
					{
						QMessageBox::critical(this, "Save Project Error!", l_strErrorMessage);
					}
				}
			}
		}
	}
}
void AppMainWindow::on_actionUser_Preferences_triggered(bool checked)
{

}
void AppMainWindow::on_actionExit_triggered(bool checked)
{
	close();
}

void AppMainWindow::on_actionModel_toggled(bool bChecked)
{
	if (bChecked)
	{
		ui.stackedWidgetCentral->setCurrentIndex(MODEL_MAINVIEW_PAGEINDEX);
	}
}
void AppMainWindow::on_actionCycle_Management_toggled(bool bChecked)
{
	if (bChecked)
	{
		ui.stackedWidgetCentral->setCurrentIndex(CYCLEMANAGEMENT_MAINVIEW_PAGEINDEX);
	}
}
void AppMainWindow::on_actionBC_Management_toggled(bool bChecked)
{
	if (bChecked)
	{
		ui.stackedWidgetCentral->setCurrentIndex(BCMANAGEMENT_MAINVIEW_PAGEINDEX);
	}
}
void AppMainWindow::on_actionAudit_Management_toggled(bool bChecked)
{
	if (bChecked)
	{
		ui.stackedWidgetCentral->setCurrentIndex(AUDITMANAGEMENT_MAINVIEW_PAGEINDEX);	
	}
	
}

void AppMainWindow::on_actionUser_Manual_triggered(bool bChecked)
{

}
void AppMainWindow::on_actionAbout_triggered(bool bChecked)
{
	
}

void AppMainWindow::closeEvent(QCloseEvent *event)
{
	on_actionClose_triggered(true);
	event->accept();
}

void AppMainWindow::initProjectViews()
{
	if (m_pApplication_Model)
	{
		QSharedPointer<Project_Model> l_pProjectModel = m_pApplication_Model->getProjectModel();
		if (!l_pProjectModel.isNull())
		{
			m_pModel_MainView = new Model_MainView(l_pProjectModel, this);
			ui.stackedWidgetCentral->insertWidget(MODEL_MAINVIEW_PAGEINDEX, m_pModel_MainView);

			QSharedPointer<CycleManagement_Model> l_pCycleManagementModel = l_pProjectModel->getCycleManagementModel();
			m_pCycleManagement_MainView = new CycleManagement_MainView(l_pCycleManagementModel, this);
			ui.stackedWidgetCentral->insertWidget(CYCLEMANAGEMENT_MAINVIEW_PAGEINDEX, m_pCycleManagement_MainView);

			QSharedPointer<BCManagement_Model> l_pBCManagementModel = l_pProjectModel->getBCManagementModel();
			m_pBCManagement_MainView = new BCManagement_MainView(l_pBCManagementModel, this);
			ui.stackedWidgetCentral->insertWidget(BCMANAGEMENT_MAINVIEW_PAGEINDEX, m_pBCManagement_MainView);

			QSharedPointer<AuditManagement_Model> l_pAuditManagementModel = l_pProjectModel->getAuditManagementModel();
			m_pAuditManagement_MainView = new AuditManagement_MainView(l_pAuditManagementModel, this);
			ui.stackedWidgetCentral->insertWidget(AUDITMANAGEMENT_MAINVIEW_PAGEINDEX, m_pAuditManagement_MainView);

			enableActions(true);
			ui.actionModel->setChecked(true);
		}
	}
}
void AppMainWindow::clearViews()
{
	ui.actionModel->setChecked(false);
	ui.actionCycle_Management->setChecked(false);
	ui.actionBC_Management->setChecked(false);
	ui.actionAudit_Management->setChecked(false);

	ui.stackedWidgetCentral->setCurrentIndex(LANDING_PAGEINDEX);

	delete m_pModel_MainView;
	delete m_pCycleManagement_MainView;
	delete m_pBCManagement_MainView;
	delete m_pAuditManagement_MainView;
}
void AppMainWindow::enableActions(bool bEnable)
{
	ui.actionModel->setEnabled(bEnable);
	ui.actionCycle_Management->setEnabled(bEnable);
	ui.actionBC_Management->setEnabled(bEnable);
	ui.actionAudit_Management->setEnabled(bEnable);

	ui.actionSave->setEnabled(bEnable);
	ui.actionSaveAs->setEnabled(bEnable);
	ui.actionClose->setEnabled(bEnable);
}