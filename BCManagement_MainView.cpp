#include "BCManagement_MainView.h"
#include "BCManagement_Model.h"

BCManagement_MainView::BCManagement_MainView(QSharedPointer<BCManagement_Model> pBCManagementModel, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

BCManagement_MainView::~BCManagement_MainView()
{}
