#include "resultpage.h"

ResultPage::ResultPage(QGraphicsItem *parent, QString mode, QString path) :
    MApplicationPage(parent),
    m_filePath(path)
{
    createContent();
    loadImage(mode, path);
}

void ResultPage::createContent()
{
    MApplicationPage::createContent();

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical, centralWidget());

    m_imageWidget = new MImageWidget(this);
    layout->addItem(m_imageWidget);

    m_pathLabel = new MLabel(this);
    layout->addItem(m_pathLabel);

    m_deleteButton = new MButton(tr("Delete"), this);
    connect(m_deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked()));
    layout->addItem(m_deleteButton);
}

void ResultPage::onDeleteButtonClicked()
{
    if (!m_filePath.isEmpty()) {
        QFile file(m_filePath);
        file.remove();
    }

    dismiss();
}

void ResultPage::loadImage(QString mode, QString path)
{
    qDebug() << path;

    m_pathLabel->setText(path);

    if (mode != "video-capture")
        m_imageWidget->setImage(QImage(path));
}
