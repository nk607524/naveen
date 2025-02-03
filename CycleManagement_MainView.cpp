#include "CycleManagement_MainView.h"
#include "CycleManagement_Model.h"

CycleManagement_MainView::CycleManagement_MainView(QSharedPointer<CycleManagement_Model> pCycleManagementModel, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

CycleManagement_MainView::~CycleManagement_MainView()
{}
