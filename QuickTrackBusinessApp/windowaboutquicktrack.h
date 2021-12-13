#ifndef WINDOWABOUTQUICKTRACK_H
#define WINDOWABOUTQUICKTRACK_H

#include <QDialog>

namespace Ui {
class windowAboutQuickTrack;
}

/**
* @brief This class is an QAction item for the QMenu.
*
* @author Jem Parlakyigit (mparlaky)
*/
class windowAboutQuickTrack : public QDialog
{
    Q_OBJECT

public:
    explicit windowAboutQuickTrack(QWidget *parent = nullptr);
    ~windowAboutQuickTrack();

private:
    Ui::windowAboutQuickTrack *ui;
};

#endif // WINDOWABOUTQUICKTRACK_H
