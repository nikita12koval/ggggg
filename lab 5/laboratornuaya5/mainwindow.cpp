#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QImage>
 #include <QFileDialog>
 #include <QBuffer>
void MainWindow::loadImage()
{
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
}

void MainWindow::saveImage();
{
 connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::SaveImage);
}



{   QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png)"));
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::saveImage);
    for (int y = 0; y < image.height(); ++y) {
        QRgb *line = reinterpret_cast<QRgb*>(image.scanLine(y));
        for (int x = 0; x < image.width(); ++x) {
            QRgb &rgb = line[x];
            rgb = qRgba(qRed(rgb), qGreen(0), qBlue(rgb), qAlpha(rgb));

        }


    }
       QImage image(3, 3, QImage::Format_Indexed8);
       QRgb value;

       value = qRgb(144, 164, 29);
       image.setColor(0, value);

       value = qRgb(227, 167, 31);
       image.setColor(1, value);

       value = qRgb(189, 149, 39);
       image.setColor(2, value);

       image.setPixel(0, 1, 0);
       image.setPixel(1, 0, 0);
       image.setPixel(1, 1, 2);
       image.setPixel(2, 1, 1);
       QImageWriter writer;
          writer.setFormat("png");
          if (writer.supportsOption(QImageIOHandler::Description));


   }



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

