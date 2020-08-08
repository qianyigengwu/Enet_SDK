#include "easyimage.h"
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>

EasyImage::EasyImage()
{
}

QPixmap EasyImage::getImages(QString url)
{
    QUrl Image_url(url);
    QNetworkAccessManager ImageGeter;
    QEventLoop loop;
    QNetworkReply *reply = ImageGeter.get(QNetworkRequest(Image_url));
    //完成后退出子事件循环
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    //开启子事件循环
    loop.exec();
    QByteArray ImageData = reply->readAll();
    QPixmap getedImage;
    getedImage.loadFromData(ImageData);
    return getedImage;
}
