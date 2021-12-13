#include "windowaboutquicktrack.h"
#include "ui_windowaboutquicktrack.h"


windowAboutQuickTrack::windowAboutQuickTrack(QWidget *parent) :QDialog(parent),ui(new Ui::windowAboutQuickTrack)
{
    ui->setupUi(this);
    this->setWindowTitle("About QuickTrack");


}

windowAboutQuickTrack::~windowAboutQuickTrack()
{
    delete ui;
}
