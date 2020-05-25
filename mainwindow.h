#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_IP_Extractor_clicked();
    void on_pushButton_IP_PORT_Extractor_clicked();
    void on_pushButton_Decimal2Dotted_clicked();
    void on_pushButton_Dotted2Decimal_clicked();
    void on_pushButton_ExportText_clicked();
    void on_pushButton_ExportCSV_clicked();

    void on_pushButton_ResolveHostnames_clicked();
    void on_pushButton_PingCheck_clicked();

    /** Receivers */
    void on_HostnameLookup_Finished(QHostInfo);

private:
    Ui::MainWindow* ui;

signals:

};

#endif // MAINWINDOW_H
