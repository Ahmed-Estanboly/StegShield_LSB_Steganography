/**
 * This code was written by Ahmed-Estanboly
 * E-mail: ahmadestanboly5@gmail.com
 * feel free to clone this repo and modify this code
 *
 * project: StegShield
 * A simple steganography program that hides text
 * within the least significant bits of the image
 * only one bit of each color of the RGB color model
**/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(4);
    ui->progressBar->setValue(0);
    QWidget::setWindowTitle("StegShield");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString filepath;
//function to check if the given text can fit in the LSBs of the image
bool canFitMessage(const QImage &image, const QString &message) {
    int maxCharacters = (image.width() * image.height() * 3) / 8;
    return message.size() + 7 <= maxCharacters;  // +5 for "\DONE" padding and +2 extra for safety
}

void MainWindow::on_browseButton_clicked()
{
    //choosinf file location via the browsing botten
    const QString desktop=QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    filepath=QFileDialog::getOpenFileName(this,tr("Open File"),desktop,"PNG (*.png)");
    ui->lineEdit->setText(filepath);
    //Displaying chosen image
    QPixmap pixMap(filepath);
    ui->imageDisplay->setPixmap(pixMap);
    ui->imageDisplay->setAlignment(Qt::AlignCenter);
    // Scale and set the image
    ui->imageDisplay->setPixmap(pixMap.scaled(300,200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    QImage image(filepath);
    int size =( ( (image.width() * image.height() * 3) / 8 ) - 8 ) / 1024;
    ui->textSizeLabel->setText("Allowed text size: " + QString::number(size) + " KB");
    ui->textEdit->setText("");
}


void MainWindow::on_hideButton_clicked()
{
    ui->progressBar->setValue(0);
    if (filepath == "")
    {
        filepath = ui->lineEdit->text();
        if (filepath == "")
        {
            QWidget window;
            QMessageBox::information(&window, "Message",  "No image was chosen.");
            return;
        }
        //Displaying chosen image
        QPixmap pixMap(filepath);
        ui->imageDisplay->setPixmap(pixMap);
        ui->imageDisplay->setAlignment(Qt::AlignCenter);
        // Scale and set the image
        ui->imageDisplay->setPixmap(pixMap.scaled(300,200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QImage image(filepath);
        int size =( ( (image.width() * image.height() * 3) / 8 ) - 8 ) / 1024;
        ui->textSizeLabel->setText("Allowed text size: " + QString::number(size) + " KB");
        ui->textEdit->setText("");
    }

    QString message = ui->textEdit->toPlainText();
    //loading the image
    QImage image(filepath);
    QByteArray data = message.toUtf8();
    if (!canFitMessage(image,message))
    {
        QWidget window;
        QMessageBox::information(&window, "Message",  "Given text is too large for this image, either input smaller text or add a bigger image.");
        return;
    }
    data.append("/DONE");  // Use custom padding terminator
    ui->progressBar->setValue(1);
    //modifying the least significant bits in each pixel
    int dataIndex = 0, bitIndex = 0;
    for (int y = 0; y < image.height(); ++y) {
        //stoping the loop when all the text is encoded in the image
        if (dataIndex >= data.size())
            break;
        for (int x = 0; x < image.width(); ++x) {
            if (dataIndex >= data.size()) break;
            //retrieving the pixel colors
            QColor color = image.pixelColor(x, y);
            //setting the LSBs to 0
            int red = color.red() & 0xFE;
            int green = color.green() & 0xFE;
            int blue = color.blue() & 0xFE;
            //encoding 1 bit in each color
            red |= (data[dataIndex] >> bitIndex) & 1;
            bitIndex ++;
            if (bitIndex == 8) {
                bitIndex = 0;
                dataIndex++;
            }
            if (dataIndex >= data.size())
            {
                image.setPixelColor(x, y, QColor(red, green, blue));
                break;
            }
            green |= (data[dataIndex] >> bitIndex) & 1;
            bitIndex ++;
            if (bitIndex == 8) {
                bitIndex = 0;
                dataIndex++;
            }
            if (dataIndex >= data.size())
            {
                image.setPixelColor(x, y, QColor(red, green, blue));
                break;
            }
            blue |= (data[dataIndex] >> bitIndex) & 1;
            image.setPixelColor(x, y, QColor(red, green, blue));
            bitIndex ++;
            if (bitIndex == 8) {
                bitIndex = 0;
                dataIndex++;
            }
        }
    }
    ui->progressBar->setValue(3);
    //renaming the new encoded image
    int lastSlashIndex = filepath.lastIndexOf('/');
    QString result = filepath.left(lastSlashIndex); // Keep everything before it
    result += "/Encoded_" + filepath.right(filepath.length() - filepath.lastIndexOf('/') - 1);
    image.save(result);
    ui->progressBar->setValue(4);
    QWidget window;
    QMessageBox::information(&window, "Message",  " The Message was hidden successfully");
}


void MainWindow::on_revealButton_clicked()
{
    ui->progressBar->setValue(0);
    if (filepath == "")
    {
        filepath = ui->lineEdit->text();
        if (filepath == "")
        {
            QWidget window;
            QMessageBox::information(&window, "Message",  "No image was chosen.");
            return;
        }
        //Displaying chosen image
        QPixmap pixMap(filepath);
        ui->imageDisplay->setPixmap(pixMap);
        ui->imageDisplay->setAlignment(Qt::AlignCenter);
        // Scale and set the image
        ui->imageDisplay->setPixmap(pixMap.scaled(300,200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        QImage image(filepath);
        int size =( ( (image.width() * image.height() * 3) / 8 ) - 8 ) / 1024;
        ui->textSizeLabel->setText("Allowed text size: " + QString::number(size) + " KB");
        ui->textEdit->setText("");
    }
    //opening the chosen image
    QImage image(filepath);
    if (image.isNull()) {
        QWidget window;
        QMessageBox::information(&window, "Message",  "Failed to open the image.");
        return;
    }
    ui->progressBar->setValue(1);
    //retrieving the hidden text in the LSBs
    QByteArray data;
    char currentByte = 0;
    int bitIndex = 0;
    bool done = 0;
    for (int y = 0; y < image.height(); ++y) {
        if (done) break;
        for (int x = 0; x < image.width(); ++x) {
            QColor color = image.pixelColor(x, y);
            currentByte |= (color.red() & 1) << bitIndex;
            bitIndex++;
            if (bitIndex == 8) {
                data.append(currentByte);
                if (data.endsWith("/DONE")) {
                    data.chop(5);  // Remove padding before returning
                    done = 1;
                    break;
                }
                currentByte = 0;
                bitIndex = 0;
            }
            currentByte |= (color.green() & 1) << bitIndex;
            bitIndex++;
            if (bitIndex == 8) {
                data.append(currentByte);
                if (data.endsWith("/DONE")) {
                    data.chop(5);  // Remove padding before returning
                    done = 1;
                    break;
                }
                currentByte = 0;
                bitIndex = 0;
            }
            currentByte |= (color.blue() & 1) << bitIndex;
            bitIndex++;
            if (bitIndex == 8) {
                data.append(currentByte);
                if (data.endsWith("/DONE")) {
                    data.chop(5);  // Remove padding before returning
                    done = 1;
                    break;
                }
                currentByte = 0;
                bitIndex = 0;
            }
        }
    }
    ui->textEdit->setText(QString::fromUtf8(data));
    ui->progressBar->setValue(4);
    QWidget window;
    QMessageBox::information(&window, "Message",  "Hidden text retrieved successfully");
}

