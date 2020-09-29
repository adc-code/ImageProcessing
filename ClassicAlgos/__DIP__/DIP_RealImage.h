////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_RealImage 
//
// Class used to manage and store an 'real' image. 
//
// Note that this class is used as a basis for three different image types, as shown in the 
// diagram:
//
//                          +------------+
//                          |  Abstract  |
//                          |   Image    |
//                          +-----+------+
//                                |
//               +----------------+----------------+
//               |                |                |
//          +----+----+     +-----+----+     +-----+-----+
//          |  Real   |     |   Image  |     |  Complex  |
//          |  Image  |     |          |     |   Image   |
//          +---------+     +----------+     +-----------+
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_AbstractImage.h"
#include "DIP_Defs.h"


#ifndef __DIP_REALIMAGE_H__
#define __DIP_REALIMAGE_H__


class DIP_RealImage :  public virtual DIP_AbstractImage <DIP_REALPIXEL_TYPE>
{
    public:

        DIP_RealImage ( unsigned int iWidth, unsigned int iHeight, DIP_IMAGE_TYPE iType=GREY );
        DIP_RealImage ( const DIP_RealImage & iImage );
       ~DIP_RealImage ();

 
        bool  FindMinValue  ( DIP_REALPIXEL_TYPE & oMinValue );
        bool  FindMaxValue  ( DIP_REALPIXEL_TYPE & oMaxValue );


        bool  ScaleImageValuesToRange ( DIP_REALPIXEL_TYPE iMinValue, DIP_REALPIXEL_TYPE iMaxValue );

        
        void  AbsoluteValue  ();

        void  LogTransform   ( DIP_REALPIXEL_TYPE iScaleFactor );




    protected:


    private:

        DIP_RealImage ();

};


#endif//__DIP_REALIMAGE_H__


