/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	FlowElementsView class allows to select a flow element from the available list to create that element in the Design_OCCView.
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
#include "ui_FlowElementsView.h"

class FlowElementsView : public QWidget
{
	Q_OBJECT

public:
	FlowElementsView(QWidget* parent = nullptr);
	~FlowElementsView();
private:
	Ui::FlowElementsView ui;
private slots:
	void on_toolBtnTubeItems_clicked();
	void on_toolBtnLoss_RecoveryItems_clicked();
	void on_toolBtnNodeItems_clicked();
	void on_toolBtnOrificeItems_clicked();
	void on_toolBtnPumpingItems_clicked();
	void on_toolBtnSealItems_clicked();
	void on_toolBtnFunctionItems_clicked();
	void on_listWidgetNodeItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetOrificeItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetLoss_RecoveryItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetTubeItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetPumpingItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetSealItems_itemClicked(QListWidgetItem* item);
	void on_listWidgetFunctionItems_itemClicked(QListWidgetItem* item);
};
