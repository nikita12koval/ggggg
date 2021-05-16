#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QImage>
#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
namespace Ui { class QFileDialog;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
public slots:
void QImage();
convertTo(QImage::Format_ARGB32);


    void loadImage();
QString fileName = QFileDialog::getOpenFileName(this, ("Загрузить картинку"), "", ("Допустимые форматы (*.png)"));
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
