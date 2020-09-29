
#ifndef __DIP_IMAGE_MASKELEMENT__
#define __DIP_IMAGE_MASKELEMENT__


enum DIP_MASK_EDGE
{
    EDGE_INSIDE    =  1, 
    EDGE_SOFTEDGE  =  2,
    EDGE_OUTSIDE   =  3
};


class DIP_Image_MaskElement
{
    public:

        DIP_Image_MaskElement ( unsigned int iCenterX, 
                                unsigned int iCenterY, 
                                int          iInnerRadius, 
                                int          iOuterRadius = 0 );


        //
        // TestPoint* 
        //
        double          TestPointValue   (unsigned int iX, unsigned int iY);
        DIP_MASK_EDGE   TestPointRegion  (unsigned int iX, unsigned int iY);


        unsigned int  _nCenterX;
        unsigned int  _nCenterY;
        int           _nInnerRadius;
        int           _nOuterRadius;

};


#endif//__DIP_IMAGE_MASKELEMENT__


