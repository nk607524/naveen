/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Design View created inside Model_MainView to enable the creation of flow resistive elements.
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
#pragma once

#include <QMainWindow>
#include "ui_DesignView.h"
#include <QPointer>

class Design_OccView;
class FlowOPNode_Model;

class DesignView : public QMainWindow
{
	Q_OBJECT

public:
	DesignView(QSharedPointer<FlowOPNode_Model> pFlowOPNode_Model, QWidget* parent = Q_NULLPTR);
	~DesignView();
private:
	Ui::DesignView ui;
	
	QPointer<Design_OccView> m_pOccView;
	QSharedPointer<FlowOPNode_Model> m_pFlowOPNode_Model;

	void init();
};
