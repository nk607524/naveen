#include "GlobalDefinitions.h"
#include "DesignView.h"
#include "Design_OccView.h"
#include "FlowOPNode_Model.h"
#include "DesignToolBarWidgets.h"

DesignView::DesignView(QSharedPointer<FlowOPNode_Model> pFlowOPNodel_Model, QWidget* parent)
    : QMainWindow(parent), m_pFlowOPNode_Model(pFlowOPNodel_Model)
{
    ui.setupUi(this);
    init();
}
DesignView::~DesignView()
{}
void DesignView::init()
{
    m_pOccView = new Design_OccView(m_pFlowOPNode_Model, this);
    ui.vLayoutCentralWidget->addWidget(m_pOccView);
}