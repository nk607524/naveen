#include "ModelDetailsView.h"

ModelDetailsView::ModelDetailsView(QSharedPointer<FlowOPNode_Model> pFlowOPNode_Model, QWidget *parent)
	: QMainWindow(parent), m_pFlowOPNode_Model(pFlowOPNode_Model)
{
	ui.setupUi(this);
}

ModelDetailsView::~ModelDetailsView()
{}
