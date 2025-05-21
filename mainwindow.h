#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <bits/stdc++.h>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <qimagewriter.h>
#include <qimagereader.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();

    void on_hideButton_clicked();

    void on_revealButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
