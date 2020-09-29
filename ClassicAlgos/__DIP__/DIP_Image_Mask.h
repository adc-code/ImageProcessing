

#ifndef __DIP_IMAGE_MASK_H__
#define __DIP_IMAGE_MASK_H__


#include "DIP_Image_MaskElement.h"

#include <vector>
using namespace std;


class DIP_Image_Mask
{
    public:

        DIP_Image_Mask ();
       ~DIP_Image_Mask ();

         
        void    AddMaskElement ( unsigned int iX, unsigned int iY, unsigned int iRadius );
        bool    DelMaskElement ( int iElemNum );

        int     GetNumElements ();

        bool    GetElementValues ( int iElemNum, unsigned int & oX, unsigned int & oY, unsigned int & oRadius ); 
        bool    SetElementValues ( int iElemNum, unsigned int   iX, unsigned int   iY, unsigned int   iRadius ); 

     
        DIP_MASK_EDGE  TestPointRegion ( unsigned int iX, unsigned int iY );
        double         TestPointValue  ( unsigned int iX, unsigned int iY );

 
        bool    GetMode ();
        void    SetMode (bool iMode);


    private:

        vector<DIP_Image_MaskElement>  _MaskElements;


        //
        // bMode... 
        //    true = direct; false = inverse
        //
        bool                           _bMode; 

};



#endif//__DIP_IMAGE_MASK_H__


