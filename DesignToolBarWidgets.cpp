/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Widget for toolbar items in Design View.
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
#include "DesignToolBarWidgets.h"
#include "Application_Model.h"
#include "Project_Model.h"
#include "FlowOPNode_Model.h"

DesignToolBarWidgets::DesignToolBarWidgets(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    updateActiveSubSystem();
}
DesignToolBarWidgets::~DesignToolBarWidgets()
{}
void DesignToolBarWidgets::updateActiveSubSystem()
{
    QSharedPointer<Application_Model> l_pApplication_Model = Application_Model::getInstance();
    if (!l_pApplication_Model.isNull())
    {
        QSharedPointer<Project_Model> l_pProject_Model = l_pApplication_Model->getProjectModel();
        if (!l_pProject_Model.isNull())
        {
            ui.comboBoxActiveSubsystem->addItems(l_pProject_Model->getSubSystemList());
        }
    }
    if (FlowOPNode_Model::ms_iActiveSubSystemIndex >= 0 && FlowOPNode_Model::ms_iActiveSubSystemIndex < ui.comboBoxActiveSubsystem->count())
    {
        ui.comboBoxActiveSubsystem->setCurrentIndex(FlowOPNode_Model::ms_iActiveSubSystemIndex);
    }
}