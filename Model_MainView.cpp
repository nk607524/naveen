#include "GlobalDefinitions.h"
#include "Model_MainView.h"
#include "DesignView.h"
#include "OutputView.h"
#include "ModelDetailsView.h"

#include "Project_Model.h"
#include "FlowTree_Model.h"
#include "SubsystemMapping_Model.h"
#include "FlowOPNode_Model.h"

#include <QComboBox>
#include <QSignalMapper>

constexpr auto SUBSYSTEM_COL_INDEX = 0;
constexpr auto COMPONENT_COL_INDEX = 1;

Model_MainView::Model_MainView(QSharedPointer<Project_Model> pProjectModel,QWidget *parent)
    : m_pProject_Model(pProjectModel), QMainWindow(parent)
{
    ui.setupUi(this);
    initChildViews();
}

Model_MainView::~Model_MainView()
{
}
void Model_MainView::initChildViews()
{
    if (!m_pProject_Model.isNull())
    {
        QSharedPointer<FlowTree_Model> l_pFlowTree_Model = m_pProject_Model->getFlowTreeModel();
        ui.widgetFlowModels->setMainViewContainer(ui.hLayoutCentralView);
        ui.widgetFlowModels->setModel(l_pFlowTree_Model);
        
        //tabifyDockWidget(ui.dockWidgetFlowModel, ui.dockWidgetSubSystemMapping);
        //ui.dockWidgetFlowModel->raise();

        UpdateSubsystemMappingView();
    }
}
void Model_MainView::UpdateSubsystemMappingView()
{
    ui.tableWidgetSubsystemMapping->setRowCount(m_pProject_Model->mc_iSubsystemCount);
    QSignalMapper* l_pSignalMapperComponent = new QSignalMapper(this);
    for (int l_nRowIndx = 0; l_nRowIndx < m_pProject_Model->mc_iSubsystemCount; ++l_nRowIndx)
    {   
        
        pair_SubsystemComponent pairValue;
        if (m_pProject_Model->getSubsystemComponentPair(l_nRowIndx, pairValue))
        {
            QString l_strSubsystemName = pairValue.first;
            en_ComponentName l_enComponentName = pairValue.second;
            QTableWidgetItem* l_pTableWidgetItemSubsystem = new QTableWidgetItem(l_strSubsystemName);
            ui.tableWidgetSubsystemMapping->setItem(l_nRowIndx, 0, l_pTableWidgetItemSubsystem);

            QComboBox* l_pCBComponent = new QComboBox(this);
            l_pCBComponent->addItems(g_liststrComponet);
            connect(l_pCBComponent, SIGNAL(currentIndexChanged(int)), l_pSignalMapperComponent, SLOT(map()));
            l_pSignalMapperComponent->setMapping(l_pCBComponent, l_nRowIndx);
            ui.tableWidgetSubsystemMapping->setCellWidget(l_nRowIndx, COMPONENT_COL_INDEX, l_pCBComponent);
        }
    }
    connect(l_pSignalMapperComponent, SIGNAL(mapped(int)), this, SLOT(on_CBComponent_Changed(int)));
}

void Model_MainView::on_CBComponent_Changed(int iRowIndex)
{
    QComboBox* l_pCBComponent = qobject_cast<QComboBox*>(ui.tableWidgetSubsystemMapping->cellWidget(iRowIndex,COMPONENT_COL_INDEX));
    QString l_strErrorMsg;
    if(!m_pProject_Model->updateComponentName(iRowIndex, en_ComponentName(l_pCBComponent->currentIndex()), l_strErrorMsg))
    {
        //Display Error
    }
}
void Model_MainView::on_tableWidgetSubsystemMapping_cellChanged(int iRowIndex, int iColIndex)
{
    if (iColIndex == SUBSYSTEM_COL_INDEX)
    {
        QString l_strSubsystemName = ui.tableWidgetSubsystemMapping->item(iRowIndex, iColIndex)->text();
        QString l_strErrorMsg;
        if (!m_pProject_Model->updateSubSystemName(iRowIndex, l_strSubsystemName, l_strErrorMsg))
        {
            //Display Error
        }
    }
}