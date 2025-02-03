#include "Outputview.h"

Outputview::Outputview(QSharedPointer<FlowOPNode_Model> pFlowOPNode_Model,QWidget *parent)
	: QWidget(parent), m_pFlowOPNode_Model(pFlowOPNode_Model)
{
	ui.setupUi(this);
}

Outputview::~Outputview()
{}
