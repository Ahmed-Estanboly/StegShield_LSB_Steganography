/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *textSizeLabel;
    QTextEdit *textEdit;
    QLabel *imageDisplay;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *hideButton;
    QFrame *line_2;
    QPushButton *revealButton;
    QProgressBar *progressBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(608, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        QFont font1;
        font1.setBold(false);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        browseButton->setFont(font2);

        horizontalLayout->addWidget(browseButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(true);
        label_2->setFont(font3);

        horizontalLayout_2->addWidget(label_2);

        textSizeLabel = new QLabel(centralwidget);
        textSizeLabel->setObjectName("textSizeLabel");

        horizontalLayout_2->addWidget(textSizeLabel);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);

        imageDisplay = new QLabel(centralwidget);
        imageDisplay->setObjectName("imageDisplay");

        gridLayout->addWidget(imageDisplay, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        hideButton = new QPushButton(centralwidget);
        hideButton->setObjectName("hideButton");
        QFont font4;
        font4.setPointSize(10);
        hideButton->setFont(font4);

        horizontalLayout_3->addWidget(hideButton);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(line_2);

        revealButton = new QPushButton(centralwidget);
        revealButton->setObjectName("revealButton");
        revealButton->setFont(font4);

        horizontalLayout_3->addWidget(revealButton);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 5, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Image Path:", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        textSizeLabel->setText(QCoreApplication::translate("MainWindow", "Allowed text size: ", nullptr));
        imageDisplay->setText(QCoreApplication::translate("MainWindow", "Your image will be displayed here", nullptr));
        hideButton->setText(QCoreApplication::translate("MainWindow", "Hide Message", nullptr));
        revealButton->setText(QCoreApplication::translate("MainWindow", "Reveal Message", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
