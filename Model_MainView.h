/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	Main View for the Model module.
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

#include <QtWidgets/QMainWindow>
#include "ui_Model_MainView.h"
#include <QPointer>

class DesignView;
class ModelDetailsView;
class Outputview;
class Project_Model;

class Model_MainView : public QMainWindow
{
    Q_OBJECT

public:
    Model_MainView(QSharedPointer<Project_Model> pProjectModel, QWidget *parent = nullptr);
    ~Model_MainView();

private slots:
    void on_CBComponent_Changed(int iRowIndex);
    void on_tableWidgetSubsystemMapping_cellChanged(int iRowIndex, int iColIndex);
private:
    Ui::Model_MainView ui;
   
    QPointer<DesignView> m_pDesignView;
    QPointer <Outputview> m_pOutputview;
    QPointer<ModelDetailsView> m_pModelDetailsView;
    QSharedPointer<Project_Model> m_pProject_Model;

    void initChildViews();
    void UpdateSubsystemMappingView();
};
