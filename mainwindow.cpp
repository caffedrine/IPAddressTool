#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QUtil.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_IP_Extractor_clicked()
{
    /* Get text from the box */
    QString data = ui->textEdit->toPlainText();

    /* Extract IPv4 addresses from given string */
    QStringList ips = ipv4util::ExtractIPv4Addresses(data);

    /* Clean text so we can add extracted ip addresses */
    ui->textEdit->clear();

    foreach (QString ip, ips) {
        ui->textEdit->append(ip);
    }
}

void MainWindow::on_pushButton_IP_PORT_Extractor_clicked()
{
    /* Get text from the box */
    QString data = ui->textEdit->toPlainText();

    /* Proxy pattern */
    QString regexPattern = "([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3})(:|[\\s]+)([0-9]{1,5})";

    /* Fetch proxies from string */
    QStringList proxies = ipv4util::GetMatches(regexPattern, data);

    /* Clean text so we can add extracted ip addresses */
    ui->textEdit->clear();

    foreach (QString proxy, proxies) {
        ui->textEdit->append(proxy.replace(QRegularExpression("[\\s]+"), ":"));
    }
}

void MainWindow::on_pushButton_Decimal2Dotted_clicked()
{
    /* Get text from the box */
    QString data = ui->textEdit->toPlainText();

    /* Decimal IP address regex validator */
    QString pattern = "[0-9]{8,12}";

    /* Extract IPv4 addresses from given string */
    QStringList ips = ipv4util::GetMatches(pattern, data);

    foreach (QString ip, ips) {
        data = data.replace(ip, ipv4util::Long2DottedIPv4(ip.toLong()));
    }

    /* Write string back to textEdit */
    ui->textEdit->setText(data);
}

void MainWindow::on_pushButton_Dotted2Decimal_clicked()
{
    /* Get text from the box */
    QString data = ui->textEdit->toPlainText();

    /* Extract IPv4 addresses from given string */
    QStringList ips = ipv4util::ExtractIPv4Addresses(data);

    foreach (QString ip, ips) {
        data = data.replace(ip, QString::number(ipv4util::Dotted2LongIPv4(ip)));
    }

    /* Write string back to textEdit */
    ui->textEdit->setText(data);
}

void MainWindow::on_pushButton_ExportText_clicked()
{
}

void MainWindow::on_pushButton_ExportCSV_clicked()
{
}

void MainWindow::on_pushButton_ResolveHostnames_clicked()
{
    /* Get text from the box */
    QString data = ui->textEdit->toPlainText();

    /* Extract IPv4 addresses from given string */
    QStringList ips = ipv4util::ExtractIPv4Addresses(data);

    foreach (QString ip, ips)
    {
        QHostInfo::lookupHost(ip, this, SLOT(on_HostnameLookup_Finished(QHostInfo)));
    }
}

void MainWindow::on_pushButton_PingCheck_clicked()
{
}

/** SLOTS */

void MainWindow::on_HostnameLookup_Finished(QHostInfo info)
{
    if( info.error() == QHostInfo::NoError )
    {
        /* Get text from the box */
        QString data = ui->textEdit->toPlainText();

        QString ip = info.addresses()[0].toString();
        QString hostname = info.hostName();

        if( ip != hostname )
        {
            data = data.replace( ip, ip + " - " + hostname );

            /* Write string back to textEdit */
            ui->textEdit->setText(data);
        }
    }
}

