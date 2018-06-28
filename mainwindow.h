#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_IP_Extractor_clicked();

    void on_pushButton_IP_PORT_Extractor_clicked();

    void on_pushButton_Decimal2Dotted_clicked();

    void on_pushButton_Dotted2Decimal_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
