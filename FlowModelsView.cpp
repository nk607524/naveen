#include "GlobalDefinitions.h"
#include "FlowModelsView.h"
#include "DesignView.h"
#include "Outputview.h"
#include "ModelDetailsView.h"
#include "FlowTree_Model.h"
#include "FlowNode_Model.h"

FlowModelsView::FlowModelsView(QWidget* parent)
    : QWidget(parent), m_phLayoutCentralWidget(Q_NULLPTR)
{
    ui.setupUi(this);
}
FlowModelsView::~FlowModelsView()
{
}
void FlowModelsView::setMainViewContainer(QPointer<QHBoxLayout> pLayoutCentralWidget)
{
    m_phLayoutCentralWidget = pLayoutCentralWidget;
}
void FlowModelsView::setModel(QSharedPointer<FlowTree_Model> pFlowTree_Model)
{
    m_pFlowTree_Model = pFlowTree_Model;
    if (!m_pFlowTree_Model.isNull())
    {
        QPointer<QStandardItemModel> l_pTreeItemModel = m_pFlowTree_Model->getTreeItemModel();
        if (l_pTreeItemModel)
        {
            ui.treeViewFlowModel->setModel(l_pTreeItemModel.data());
            ui.treeViewFlowModel->expandAll();
        }
    }
}
void FlowModelsView::on_treeViewFlowModel_clicked(const QModelIndex& index)
{
    if (!m_pFlowTree_Model.isNull())
    {
        QStandardItemModel* l_pTreeItemModel = dynamic_cast<QStandardItemModel *>(ui.treeViewFlowModel->model());
        if (l_pTreeItemModel)
        {
            FlowNode_Model* l_pFlowNode_Model = dynamic_cast<FlowNode_Model*>(l_pTreeItemModel->itemFromIndex(index));
            if (l_pFlowNode_Model)
            {
                switch (l_pFlowNode_Model->getTreeNodeType())
                {
                case FlowNode_Model::OP_NODE:
                {
                    QString l_strOPNodeID = l_pFlowNode_Model->getTreeNodeID();
                    createOPNodeView(l_strOPNodeID);
                }
                break;
                default:
                    delete m_pTabWidgetOPNodeView;
                }
            }
        }

    }
}
void FlowModelsView::createOPNodeView(const QString& pOPNodeID)
{
    delete m_pTabWidgetOPNodeView;
    m_pTabWidgetOPNodeView = new QTabWidget(this);
    QSharedPointer<FlowOPNode_Model> l_pFlowOPNode_Model = m_pFlowTree_Model->getFlowOPNodeModel(pOPNodeID);
    if (!l_pFlowOPNode_Model.isNull())
    {
        QPointer<DesignView> m_pDesignView = new DesignView(l_pFlowOPNode_Model, m_pTabWidgetOPNodeView);
        QPointer<ModelDetailsView> m_pModelDetailsView = new ModelDetailsView(l_pFlowOPNode_Model, m_pTabWidgetOPNodeView);
        QPointer<Outputview> m_pOutputview = new Outputview(l_pFlowOPNode_Model, m_pTabWidgetOPNodeView);

        m_pTabWidgetOPNodeView->addTab(m_pDesignView, g_cstrDesignview);
        m_pTabWidgetOPNodeView->addTab(m_pModelDetailsView, g_cstrModelDetails);
        m_pTabWidgetOPNodeView->addTab(m_pOutputview, g_cstrOutputDEtails);

        if (!m_phLayoutCentralWidget.isNull())
            m_phLayoutCentralWidget->addWidget(m_pTabWidgetOPNodeView);
    }
    else
    {
        //ToDo::
    }
}
