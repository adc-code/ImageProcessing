
#include <QImage>

#include "DIP_Image.h"


#ifndef __DIP_QT_UTILS_H__
#define __DIP_QT_UTILS_H__


class DIP_QT_Utils
{
    public:
     
        static  bool  ConvertQImageToDIPImage ( QImage & iQImage, DIP_Image *& oDIPImage );

        static  bool  ConvertDIPImageToQImage ( DIP_Image * iDIPImage, QImage & oQImage );

};


#endif//__DIP_QT_UTILS_H__


