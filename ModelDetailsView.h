#pragma once

#include "ui_ModelDetailsView.h"

class FlowOPNode_Model;
class ModelDetailsView : public QMainWindow
{
	Q_OBJECT

public:
	ModelDetailsView(QSharedPointer<FlowOPNode_Model> pFlowOPNode_Model,QWidget *parent = nullptr);
	~ModelDetailsView();

private:
	Ui::ModelDetailsViewClass ui;
	QSharedPointer<FlowOPNode_Model> m_pFlowOPNode_Model;
};
