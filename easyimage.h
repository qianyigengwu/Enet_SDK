#ifndef EASYIMAGE_H
#define EASYIMAGE_H
#include <QString>
#include <QPixmap>

class EasyImage
{
public:
    EasyImage();
    QPixmap getImages(QString url);
};

#endif // EASYIMAGE_H
