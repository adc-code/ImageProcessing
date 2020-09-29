////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_RealImage 
//
// Class used to manage and store an 'real' image. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_AbstractImage.h"
#include "DIP_RealImage.h"

#include <cmath>
#include <iostream>
using namespace std;


template class DIP_AbstractImage <DIP_REALPIXEL_TYPE>;



DIP_RealImage::DIP_RealImage ( unsigned int iWidth, unsigned int iHeight, DIP_IMAGE_TYPE iType ) 
                : DIP_AbstractImage <DIP_REALPIXEL_TYPE> ( iWidth, iHeight, iType )
{
}
 


DIP_RealImage::DIP_RealImage ( const DIP_RealImage & iImage )
                : DIP_AbstractImage <DIP_REALPIXEL_TYPE> ( iImage )
{
}



DIP_RealImage::~DIP_RealImage ()
{
}



bool DIP_RealImage::FindMinValue ( DIP_REALPIXEL_TYPE & oMinValue )
{
    cout << "DIP_RealImage::FindMinValue" << endl;

    bool bRetVal = false;
  
    double dMinValue = HUGE_VAL;

    for (int i = 0; i < _ImgType; i++)
    {
        for (int j = 0; j < _nBufferSize; j++)
        {
           if ( _PixelData [ i ][ j ] < dMinValue )
               dMinValue = _PixelData [ i ][ j ];
        }             
    }

    if (dMinValue != HUGE_VAL)
    {
        oMinValue = dMinValue;
        bRetVal   = true;
    }
 
    return bRetVal;
}



bool DIP_RealImage::FindMaxValue ( DIP_REALPIXEL_TYPE & oMaxValue )
{
    cout << "DIP_RealImage::FindMaxValue" << endl;

    bool bRetVal = false;
   
    double dMaxValue = -HUGE_VAL;

    for (int i = 0; i < _ImgType; i++)
    {
        for (int j = 0; j < _nBufferSize; j++)
        {
           if ( _PixelData [ i ][ j ] > dMaxValue )
           {
               dMaxValue = _PixelData [ i ][ j ];
               //cout << " %%%  " << dMaxValue << "  %%% " << endl;
           }
           //cout << _PixelData [ i ][ j ] << endl;
        }             
    }

    if (dMaxValue != -HUGE_VAL)
    {
        oMaxValue = dMaxValue;
        bRetVal   = true;
    }
 
    return bRetVal;
}

 

bool DIP_RealImage::ScaleImageValuesToRange ( DIP_REALPIXEL_TYPE iMinValue, DIP_REALPIXEL_TYPE iMaxValue )
{
    cout << "DIP_RealImage::ScaleImageValuesToRange" << endl;

    bool bRetVal = false;

    double dMinValue = 0;
    FindMinValue (dMinValue);

    double dMaxValue = 0;
    FindMaxValue (dMaxValue);
    
    double dDelta    = dMaxValue - dMinValue;
    double dNewDelta = iMaxValue - iMinValue;

    cout << "   dMinValue = " << dMinValue << "   dMaxValue = " << dMaxValue << "  dDelta = " << dDelta << endl;
    cout << "   iMinValue = " << iMinValue << "   iMaxValue = " << iMaxValue << "  dNewDelta = " << dNewDelta << endl;

    if ( fabs(dDelta) > DIP_MATH_EPS && fabs(dNewDelta) > DIP_MATH_EPS )
    {
        for (int i = 0; i < _ImgType; i++)
        {
            for (int j = 0; j < _nBufferSize; j++)
            {
                //_PixelData [ i ][ j ] = (_PixelData [ i ][ j ] - dMinValue) / dDelta * dNewDelta + iMinValue;
                if (_PixelData [ i ][ j ] < 0)
                    _PixelData [ i ][ j ] = 0;
                else if (_PixelData [ i ][ j ] > 255)
                    _PixelData [ i ][ j ] = 255;
            }             
        }
        
        bRetVal = true;
    }

    return bRetVal;
}

 
      
void DIP_RealImage::AbsoluteValue ()
{
    for (int i = 0; i < _ImgType; i++)
    {
        for (int j = 0; j < _nBufferSize; j++)
        {
            _PixelData [ i ][ j ] = fabs ( _PixelData [ i ][ j ] );
        }             
    }
}



void DIP_RealImage::LogTransform ( DIP_REALPIXEL_TYPE iScaleFactor )
{
    double dMinValue = 0;
    double dMaxValue = 0;

    FindMinValue (dMinValue);
    FindMaxValue (dMaxValue);

    double temp = fabs (dMaxValue - dMinValue);
    temp = exp ( temp - 1);

    dMinValue = fabs (dMinValue);
    dMaxValue = fabs (dMaxValue);

    double dFabsMax = dMinValue;
    if (dMaxValue > dFabsMax)
        dFabsMax = dMaxValue; 
     
    if (dFabsMax < DIP_MATH_EPS) 
        dFabsMax = 1;

    
    for (int i = 0; i < _ImgType; i++)
    {
        for (int j = 0; j < _nBufferSize; j++)
        {
            _PixelData [ i ][ j ] = log ( iScaleFactor * fabs (_PixelData [ i ][ j ]) / dFabsMax + 1);
            //_PixelData [ i ][ j ] = log ( temp * fabs (_PixelData [ i ][ j ]) / dFabsMax + 1);
            //_PixelData [ i ][ j ] = log ( temp * fabs (_PixelData [ i ][ j ]) + 1);
        }
    } 
} 


