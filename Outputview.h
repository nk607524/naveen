#pragma once

#include <QWidget>
#include "ui_Outputview.h"

class FlowOPNode_Model;
class Outputview : public QWidget
{
	Q_OBJECT

public:
	Outputview(QSharedPointer<FlowOPNode_Model> pFlowOPNode_Model, QWidget *parent = Q_NULLPTR);
	~Outputview();

private:
	Ui::OutputviewClass ui;
	QSharedPointer<FlowOPNode_Model> m_pFlowOPNode_Model;
};
