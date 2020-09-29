


#include "DIP_Image_Mask.h"
#include "DIP_Image_MaskElement.h"


DIP_Image_Mask::DIP_Image_Mask ()
{
    _bMode = true;
}



DIP_Image_Mask::~DIP_Image_Mask ()
{
}



void DIP_Image_Mask::AddMaskElement ( unsigned int iX, unsigned int iY, unsigned int iRadius )
{
    DIP_Image_MaskElement element ( iX, iY, iRadius );

    _MaskElements.push_back (element);
}
    

 
bool DIP_Image_Mask::DelMaskElement ( int iElemNum )
{
    bool bOK = false;

    if ( iElemNum >= 0 && iElemNum < _MaskElements.size () )
    {
        _MaskElements.erase ( _MaskElements.begin() + iElemNum );
        bOK = true;
    }

    return bOK;
}


 
double DIP_Image_Mask::TestPointValue ( unsigned int iX, unsigned int iY )
{
    double dResults = 0;

    for (int i = 0; i < _MaskElements.size (); i++)
    {
        if ( _MaskElements[i].TestPointValue (iX, iY) )
        {
            dResults = 1.0;
            break;
        } 
    }

    if (!_bMode)
        dResults = 1.0 - dResults;

    return dResults;
}



DIP_MASK_EDGE DIP_Image_Mask::TestPointRegion ( unsigned int iX, unsigned int iY )
{
    DIP_MASK_EDGE region = EDGE_OUTSIDE;

    /*for (int i = 0; i < _MaskElements.size (); i++)
    {
        if ( _MaskElements[i].TestPointRegion (iX, iY) )
        {
            dResults = 1.0;
            break;
        } 
    }*/

    return region;   
}



int DIP_Image_Mask::GetNumElements ()
{
    return _MaskElements.size ();
}



bool DIP_Image_Mask::GetElementValues ( int iElemNum, unsigned int & oX, unsigned int & oY, unsigned int & oRadius )
{
    bool bOK = false;

    if ( iElemNum >= 0 && iElemNum < _MaskElements.size() )
    {
        oX      = _MaskElements [iElemNum]._nCenterX;
        oY      = _MaskElements [iElemNum]._nCenterY;
        oRadius = _MaskElements [iElemNum]._nInnerRadius;

        bOK = true;
    }

    return bOK;
}



bool DIP_Image_Mask::SetElementValues ( int iElemNum, unsigned int iX, unsigned int iY, unsigned int iRadius )
{
    bool bOK = false;

    if ( iElemNum >= 0 && iElemNum < _MaskElements.size() )
    {
        _MaskElements [iElemNum]._nCenterX      = iX;
        _MaskElements [iElemNum]._nCenterY      = iY;
        _MaskElements [iElemNum]._nInnerRadius  = iRadius;

        bOK = true;
    } 

    return bOK;
}



bool DIP_Image_Mask::GetMode ()
{
    return _bMode;
}


void DIP_Image_Mask::SetMode (bool iMode)
{
    _bMode = iMode;
}



