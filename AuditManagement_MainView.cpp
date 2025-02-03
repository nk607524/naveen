#include "AuditManagement_MainView.h"
#include "AuditManagement_Model.h"

AuditManagement_MainView::AuditManagement_MainView(QSharedPointer<AuditManagement_Model> pAuditManagementModel, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

AuditManagement_MainView::~AuditManagement_MainView()
{}
