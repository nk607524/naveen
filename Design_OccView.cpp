#include "Design_OccView.h"
#include <QApplication>
#include <QCursor>

#include <OpenGl_GraphicDriver.hxx>
#include <V3d_View.hxx>
#include <V3d_Viewer.hxx>

#include <WNT_Window.hxx>

Design_OccView::Design_OccView(QSharedPointer<FlowOPNode_Model> pFlowOPNodel_Model, QWidget* parent )
    : QWidget(parent), m_pFlowOPNodel_Model(pFlowOPNodel_Model)
{
    m_rCurZoom = 0;
    setAutoFillBackground(false);
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_NativeWindow);

    m_enCurrentMode = CurAction3d_Nothing;
    setMouseTracking(true);

    setBackgroundRole(QPalette::NoRole);//NoBackground );
    // set focus policy to threat QContextMenuEvent from keyboard  
    setFocusPolicy(Qt::StrongFocus);
    init();
}
Design_OccView::~Design_OccView()
{
}
void Design_OccView::init()
{
    Handle(Aspect_DisplayConnection) l_pDisplayConnection = new Aspect_DisplayConnection();
    Handle(Graphic3d_GraphicDriver) l_pGraphicDriver = new OpenGl_GraphicDriver(l_pDisplayConnection);

    m_pV3d_Viewer = new V3d_Viewer(l_pGraphicDriver);
    m_pAIS_InteractiveContext = new AIS_InteractiveContext(m_pV3d_Viewer);
    m_pV3d_View = m_pV3d_Viewer->CreateView();

    if (m_pV3d_View.IsNull())
        m_pV3d_View = m_pAIS_InteractiveContext->CurrentViewer()->CreateView();

    // Get window handle. This returns something suitable for all platforms.
    WId window_handle = (WId)winId();
    #ifdef WNT
        Handle(WNT_Window) hWnd = new WNT_Window((Aspect_Window*)window_handle);
        hWnd->SetBackground(Quantity_NOC_MATRAGRAY);
    #else
        Handle(Xw_Window) hWnd = new Xw_Window(Handle(Graphic3d_GraphicDevice)::DownCast(m_pContext->CurrentViewer()->Device()), (int)hi, (int)lo, Xw_WQ_SAMEQUALITY);
    #endif // WNT
    m_pV3d_View->SetWindow(hWnd);
    if (!hWnd->IsMapped())
    {
        hWnd->Map();
    }
    m_pV3d_View->SetBackgroundColor(Quantity_NOC_BLACK);
    m_pV3d_View->MustBeResized();
}

QPaintEngine* Design_OccView::paintEngine() const
{
    return 0;
}
void Design_OccView::paintEvent(QPaintEvent*)
{
    if(!m_pV3d_Viewer.IsNull())
        m_pV3d_Viewer->Update();
}
void Design_OccView::resizeEvent(QResizeEvent*)
{
    //  QApplication::syncX();
    if (!m_pV3d_View.IsNull())
    {
        m_pV3d_View->MustBeResized();
    }
}

void Design_OccView::fitAll()
{
    m_pV3d_View->FitAll();
    m_pV3d_View->ZFitAll();
    m_pV3d_View->Redraw();
}
void Design_OccView::fitArea()
{
    setCurrentAction(CurAction3d_WindowZooming);
}
void Design_OccView::zoom()
{
    setCurrentAction(CurAction3d_DynamicZooming);
}
void Design_OccView::pan()
{
    setCurrentAction(CurAction3d_DynamicPanning);
}
void Design_OccView::rotation()
{
    setCurrentAction(CurAction3d_DynamicRotation);
}
void Design_OccView::globalPan()
{
    // save the current zoom value
    m_rCurZoom = m_pV3d_View->Scale();
    // Do a Global Zoom
    m_pV3d_View->FitAll();
    // Set the mode
    setCurrentAction(CurAction3d_GlobalPanning);
}
void Design_OccView::front()
{
    m_pV3d_View->SetProj(V3d_Yneg);
}
void Design_OccView::back()
{
    m_pV3d_View->SetProj(V3d_Ypos);
}
void Design_OccView::top()
{
    m_pV3d_View->SetProj(V3d_Zpos);
}
void Design_OccView::bottom()
{
    m_pV3d_View->SetProj(V3d_Zneg);
}
void Design_OccView::left()
{
    m_pV3d_View->SetProj(V3d_Xneg);
}
void Design_OccView::right()
{
    m_pV3d_View->SetProj(V3d_Xpos);
}
void Design_OccView::axo()
{
    m_pV3d_View->SetProj(V3d_XposYnegZpos);
}
void Design_OccView::reset()
{
    m_pV3d_View->Reset();
}
void Design_OccView::hlrOff()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    m_pV3d_View->SetComputedMode(false);
    m_pV3d_View->Redraw();
    QApplication::restoreOverrideCursor();
}
void Design_OccView::hlrOn()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    m_pV3d_View->SetComputedMode(true);
    m_pV3d_View->Redraw();
    QApplication::restoreOverrideCursor();
}

void Design_OccView::updateView()
{
    update();
}
bool Design_OccView::dump(QString l_strFile)
{
    return m_pV3d_View->Dump(Standard_CString(l_strFile.data()));
}
Handle(V3d_View)& Design_OccView::getView()
{
    return m_pV3d_View;
}
Handle(AIS_InteractiveContext)& Design_OccView::getContext()
{
    return m_pAIS_InteractiveContext;
}
Design_OccView::en_CurrentAction3d Design_OccView::getCurrentMode()
{
    return m_enCurrentMode;
}