/*************************************************************************
 * @Project Title : Visual Network
 * @Description	  :	QWidget derived class attached to the OCC graphical view for visualization.
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
#include <QMenu>
#include "AIS_InteractiveContext.hxx"

class V3d_View;
class V3d_Viewer;
class FlowOPNode_Model;

class Design_OccView : public QWidget
{
	Q_OBJECT
protected:
	typedef enum {
		CurAction3d_Nothing, CurAction3d_DynamicZooming,
		CurAction3d_WindowZooming, CurAction3d_DynamicPanning,
		CurAction3d_GlobalPanning, CurAction3d_DynamicRotation
	}en_CurrentAction3d;
public:
    Design_OccView(QSharedPointer<FlowOPNode_Model> pFlowOPNodel_Model, QWidget* parent = Q_NULLPTR);
    ~Design_OccView();

    virtual void init();
    virtual QPaintEngine* paintEngine() const;
    bool dump(QString l_strFile);

public slots:
    void fitAll();
    void fitArea();
    void zoom();
    void pan();
    void globalPan();
    void front();
    void back();
    void top();
    void bottom();
    void left();
    void right();
    void axo();
    void rotation();
    void reset();
    void hlrOn();
    void hlrOff();

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent*);

    Handle(V3d_View)& getView();
    Handle(AIS_InteractiveContext)& getContext();
    en_CurrentAction3d getCurrentMode();
    void updateView();

    //! Set current action.
    void setCurrentAction(en_CurrentAction3d l_enAction)
    {
        m_enCurrentMode = l_enAction;
    }

private:
    Handle(V3d_View)                 m_pV3d_View;
    Handle(AIS_InteractiveContext)   m_pAIS_InteractiveContext;
    Handle(V3d_Viewer)               m_pV3d_Viewer;
    QSharedPointer<FlowOPNode_Model> m_pFlowOPNodel_Model;

    en_CurrentAction3d               m_enCurrentMode;
    double                           m_rCurZoom;
    QMenu                            m_objMenuBack;
};

