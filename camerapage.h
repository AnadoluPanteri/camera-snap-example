#ifndef CAMERAPAGE_H
#define CAMERAPAGE_H

#include <MApplicationPage>
#include <MLabel>
#include <MButton>
#include <QGraphicsLinearLayout>
#include <QTimer>
#include "camera.h"
#include "resultpage.h"

class CameraPage : public MApplicationPage
{
    Q_OBJECT
public:
    explicit CameraPage(QGraphicsItem *parent = 0);
    
private:
    void createContent();
    Camera *m_camera;

private slots:
    void onStillButtonClicked();
    void onVideoButtonClicked();
    void onCaptureCompleted(QString mode, QString path);
};

#endif // CAMERAPAGE_H
