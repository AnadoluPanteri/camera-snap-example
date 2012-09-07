#include <MApplication>
#include <MApplicationWindow>
#include <MApplicationPage>
#include <MComponentCache>
#include <MLabel>

#include <QTimer>

#include "camerapage.h"

int main(int argc, char* argv[])
{
    MApplication *application = MComponentCache::mApplication(argc, argv);
    MApplicationWindow *window = MComponentCache::mApplicationWindow();

    CameraPage page;

    page.appear(window);
    window->show();

    return application->exec();
}
