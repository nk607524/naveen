#include "FlowElementsView.h"

FlowElementsView::FlowElementsView(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}
FlowElementsView::~FlowElementsView()
{}
void FlowElementsView::on_toolBtnTubeItems_clicked()
{
    if (ui.toolBtnTubeItems->isChecked())
    {
        ui.listWidgetTubeItems->show();
        ui.toolBtnTubeItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetTubeItems->hide();
        ui.toolBtnTubeItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnLoss_RecoveryItems_clicked()
{
    if (ui.toolBtnLoss_RecoveryItems->isChecked())
    {
        ui.listWidgetLoss_RecoveryItems->show();
        ui.toolBtnLoss_RecoveryItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetLoss_RecoveryItems->hide();
        ui.toolBtnLoss_RecoveryItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnOrificeItems_clicked()
{
    if (ui.toolBtnOrificeItems->isChecked())
    {
        ui.listWidgetOrificeItems->show();
        ui.toolBtnOrificeItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetOrificeItems->hide();
        ui.toolBtnOrificeItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnPumpingItems_clicked()
{
    if (ui.toolBtnPumpingItems->isChecked())
    {
        ui.listWidgetPumpingItems->show();
        ui.toolBtnPumpingItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetPumpingItems->hide();
        ui.toolBtnPumpingItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnSealItems_clicked()
{
    if (ui.toolBtnSealItems->isChecked())
    {
        ui.listWidgetSealItems->show();
        ui.toolBtnSealItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetSealItems->hide();
        ui.toolBtnSealItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnNodeItems_clicked()
{
    if (ui.toolBtnNodeItems->isChecked())
    {
        ui.listWidgetNodeItems->show();
        ui.toolBtnNodeItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetNodeItems->hide();
        ui.toolBtnNodeItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_toolBtnFunctionItems_clicked()
{
    if (ui.toolBtnFunctionItems->isChecked())
    {
        ui.listWidgetFunctionItems->show();
        ui.toolBtnFunctionItems->setArrowType(Qt::ArrowType::DownArrow);
    }
    else
    {
        ui.listWidgetFunctionItems->hide();
        ui.toolBtnFunctionItems->setArrowType(Qt::ArrowType::RightArrow);
    }
}
void FlowElementsView::on_listWidgetNodeItems_itemClicked(QListWidgetItem* item)
{
}
void FlowElementsView::on_listWidgetOrificeItems_itemClicked(QListWidgetItem * item)
{   
}
void FlowElementsView::on_listWidgetLoss_RecoveryItems_itemClicked(QListWidgetItem* item)
{
}
void FlowElementsView::on_listWidgetTubeItems_itemClicked(QListWidgetItem* item)
{
}
void FlowElementsView::on_listWidgetPumpingItems_itemClicked(QListWidgetItem* item)
{
}
void FlowElementsView::on_listWidgetSealItems_itemClicked(QListWidgetItem* item)
{
}
void FlowElementsView::on_listWidgetFunctionItems_itemClicked(QListWidgetItem* item)
{
}
