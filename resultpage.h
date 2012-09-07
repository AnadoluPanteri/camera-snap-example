#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <MApplicationPage>
#include <MImageWidget>
#include <MLabel>
#include <MButton>
#include <QGraphicsLinearLayout>
#include <QFile>
#include <QDebug>

class ResultPage : public MApplicationPage
{
    Q_OBJECT
public:
    explicit ResultPage(QGraphicsItem *parent = 0, QString mode = QString(), QString path = QString());
    
private:
    void createContent();
    void loadImage(QString mode, QString path);

    MImageWidget *m_imageWidget;
    MLabel *m_pathLabel;
    MButton *m_deleteButton;

    QString m_filePath;

private slots:
    void onDeleteButtonClicked();
};

#endif // RESULTPAGE_H
