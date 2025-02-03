/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	View to create, edit or delete flow models in the current project.
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

#include <QWidget>
#include "ui_FlowModelsView.h"
#include <QStandardItemModel>
#include <QPointer>

class FlowTree_Model;
class FlowModelsView : public QWidget
{
	Q_OBJECT

public:
	FlowModelsView(QWidget* parent = nullptr);
	~FlowModelsView();

	void setMainViewContainer(QPointer<QHBoxLayout> pLayoutCentralWidget);
	void setModel(QSharedPointer<FlowTree_Model> pFlowTree_Model);
private slots:
	void on_treeViewFlowModel_clicked(const QModelIndex& index);

private:
	Ui::FlowModelsView ui;
	QSharedPointer<FlowTree_Model> m_pFlowTree_Model;
	QPointer<QHBoxLayout> m_phLayoutCentralWidget;
	QPointer<QTabWidget> m_pTabWidgetOPNodeView;
	
	void createOPNodeView(const QString& pOPNodeID);
};
