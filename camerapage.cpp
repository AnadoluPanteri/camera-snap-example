#include "camerapage.h"

CameraPage::CameraPage(QGraphicsItem *parent) :
    MApplicationPage(parent)
{
    createContent();
}

void CameraPage::createContent()
{
    MApplicationPage::createContent();

    m_camera = new Camera(this);
    connect(m_camera, SIGNAL(captured(QString,QString)), this, SLOT(onCaptureCompleted(QString,QString)));

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical, centralWidget());

    MLabel *label = new MLabel(this);
    label->setText("Example application showing how to take picture from Camera using stock UI");
    label->setWordWrap(true);
    layout->addItem(label);
    layout->addStretch();

    MButton *stillButton = new MButton(tr("Still shot"), this);
    connect(stillButton, SIGNAL(clicked()), this, SLOT(onStillButtonClicked()));

    MButton *videoButton = new MButton(tr("Video mode"), this);
    connect(videoButton, SIGNAL(clicked()), this, SLOT(onVideoButtonClicked()));

    layout->addItem(stillButton);
    layout->addItem(videoButton);

    layout->setAlignment(stillButton, Qt::AlignHCenter);
    layout->setAlignment(videoButton, Qt::AlignHCenter);

    layout->addStretch();

    MLabel *ownerLabel = new MLabel(this);
    ownerLabel->setAlignment(Qt::AlignHCenter);
    ownerLabel->setText("(C) Mohammad Abu-Garbeyyeh 2012\nLicensed under GPLv3");
    ownerLabel->setWordWrap(true);
    layout->addItem(ownerLabel);
}

void CameraPage::onStillButtonClicked()
{
    m_camera->startCamera(Camera::CameraStillShot);
}

void CameraPage::onVideoButtonClicked()
{
    m_camera->startCamera(Camera::CameraVideo);
}

void CameraPage::onCaptureCompleted(QString mode, QString path)
{
    ResultPage *page = new ResultPage(this, mode, path);
    page->appear(scene(), MSceneWindow::DestroyWhenDismissed);
}
