
#include "DIP_Image_MaskElement.h"

#include <cmath>


DIP_Image_MaskElement::DIP_Image_MaskElement ( unsigned int iCenterX, 
                                               unsigned int iCenterY, 
                                               int          iInnerRadius,
                                               int          iOuterRadius )
{
    _nCenterX = iCenterX;
    _nCenterY = iCenterY;

    _nInnerRadius = iInnerRadius;
    _nOuterRadius = iOuterRadius;
}


//
// TestPointValue
//
double DIP_Image_MaskElement::TestPointValue ( unsigned int iX, unsigned int iY )
{
    double dResults = 1.0;

    int nDx = iX - _nCenterX;
    int nDy = iY - _nCenterY;

    double dRadius = sqrt ( nDx*nDx + nDy*nDy );

    if ( dRadius <= (double) _nInnerRadius )
    {
        dResults = 1.0;
    }
    else if ( dRadius <= (double) _nOuterRadius )
    {
        // do a nice gradual change between inside and outside using cosine...

        double dRValue = ( dRadius - (double) _nInnerRadius ) / 
                         ( (double) _nOuterRadius - (double) _nInnerRadius );

        dResults = 1.0 - 0.5 * ( cos ( M_PI * dRValue ) + 1 );
    }
    else
    {
        dResults = 0.0;
    }

    return dResults;
}



//
// TestPointRegion
//
DIP_MASK_EDGE DIP_Image_MaskElement::TestPointRegion ( unsigned int iX, unsigned int iY )
{
    DIP_MASK_EDGE region = EDGE_INSIDE;

    int nDx = iX - _nCenterX;
    int nDy = iY - _nCenterY;

    int nRadiusSqr = nDx*nDx + nDy*nDy;

    if ( nRadiusSqr <= _nInnerRadius*_nInnerRadius )
        region = EDGE_INSIDE;
    else if ( nRadiusSqr <= _nOuterRadius*_nOuterRadius )
        region = EDGE_SOFTEDGE;
    else
        region = EDGE_OUTSIDE;

    return region;
}




