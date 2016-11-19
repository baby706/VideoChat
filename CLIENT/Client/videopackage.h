#ifndef VIDEOPACKAGE_H
#define VIDEOPACKAGE_H

typedef struct
{
    int width;            //图象的宽
    int height;           //图象的高
    int bytesPerline;
    bool isLastPack;
    int packTaken;
    char data[4096];

}ImagePackage_t;

#endif // VIDEOPACKAGE_H
