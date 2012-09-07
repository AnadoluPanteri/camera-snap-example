#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDebug>

#define CAMERA_SERVICE "com.nokia.maemo.CameraService"
#define CAMERA_INTERFACE "com.nokia.maemo.meegotouch.CameraInterface"

#define STILL_MODE "still-capture"
#define VIDEO_MODE "video-capture"

class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = 0);

    enum CaptureMode {
        CameraStillShot,
        CameraVideo
    };

public slots:
    void startCamera(Camera::CaptureMode mode = Camera::CameraStillShot);
    
signals:
    void captured(QString mode, QString filename);
    
private slots:
    void captureCanceled(const QString &mode);
    void captureCompleted(const QString &mode, const QString &fileName);
    void disconnectSignals();
};

#endif // CAMERA_H
