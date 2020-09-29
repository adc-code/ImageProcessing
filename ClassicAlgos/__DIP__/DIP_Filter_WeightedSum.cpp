////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_WeightedSum.cpp
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_Filter_WeightedSum.h"
#include "DIP_Math_Utils.h"

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_Filter_WeightedSum::DIP_Filter_WeightedSum ( DIP_Neighbourhood *         iNeighbourhood, 
                                                 DIP_WEIGHTEDSUMFILTER_TYPE  iType, 
                                                 vector<double> &            iWeights )
               : DIP_Filter ( iNeighbourhood )
{
    _Type = iType;

    if ( _Type == WS_AVERAGE )
    {
        for ( int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++ )
        {
            _Weights.push_back ( 1.0 / _pNeighbourhood -> _nNumberOfPixels );
        }
    }
    else if ( _Type == WS_WEIGHTEDAVERAGE )
    {
        vector <double>  horizWeights;
        DIP_Math_Utils::ComputeWeights ( _pNeighbourhood -> _nRegionWidth, horizWeights );
  
        vector <double>  vertWeights;
        DIP_Math_Utils::ComputeWeights ( _pNeighbourhood -> _nRegionHeight, vertWeights );
         
        double dTotal = 0;       
        for ( int j = 0; j < _pNeighbourhood -> _nRegionHeight; j++ )
        {
            for ( int i = 0; i < _pNeighbourhood -> _nRegionWidth; i++ )
            {
                _Weights.push_back ( horizWeights[i] * vertWeights[j] );
                dTotal += _Weights.back ();
            }
        } 

        if ( dTotal > DIP_MATH_EPS)
        {
            for ( int i = 0; i < _Weights.size (); i++ )
            {
                _Weights [i] /= dTotal;
            }
        }    
    }
    else if ( _Type == WS_LAPLACIAN )
    {
        for ( int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++ )
        {
            _Weights.push_back ( 1.0 );
        }

        int nCenterOffset = (_Weights.size() - 1) / 2;
        if ( nCenterOffset )
        {
            _Weights[ nCenterOffset ] = 1 - _pNeighbourhood -> _nNumberOfPixels;
        }
    }
    else if ( _Type == WS_UNSHARP_MASK )
    {
        for ( int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++ )
        {
            _Weights.push_back ( -1.0 );
        }

        int nCenterOffset = (_Weights.size() - 1) / 2;
        if ( nCenterOffset )
        {
            _Weights[ nCenterOffset ] = ( _pNeighbourhood -> _nNumberOfPixels );
        }
    }
    else if ( _Type == WS_SOBEL_HORIZ )
    {
        ComputeSobelCoefs ( M_PI_2 );
    }
    else if ( _Type == WS_SOBEL_VERT )
    {
        ComputeSobelCoefs ( 0 );
    }
    else if ( _Type == WS_SOBEL_45_1 )
    {
        ComputeSobelCoefs ( M_PI_4 );
    }
    else if ( _Type == WS_SOBEL_45_2 )
    {
        ComputeSobelCoefs ( -1 * M_PI_4 );
    }
    else if ( _Type == WS_OTHER )
    {
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeResults...
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Filter_WeightedSum::ComputeResults ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults )
{
    bool bRetVal = false;

    if ( _pNeighbourhood )
    {
        double dTotal = 0;

        for ( int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++ )
        {   
            dTotal += _Weights [ i ] * _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ];
        }

        oResults = dTotal;
        //cout << "###   ComputeResults : " << oResults << endl;
        bRetVal  = true;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeSobelCoefs...
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DIP_Filter_WeightedSum::ComputeSobelCoefs ( double iAngle )
{
    if (_pNeighbourhood)
    {
        int nXDelta = (_pNeighbourhood -> _nRegionWidth >> 1);
        int nYDelta = (_pNeighbourhood -> _nRegionHeight >> 1);

        for (int j = -nYDelta; j <= nYDelta; j++)
        {
            for (int i = -nXDelta; i <= nXDelta; i++)
            {
                if ( i == j )
                    _Weights.push_back ( 0 );
                else
                {
                    _Weights.push_back ( (i*cos(iAngle) + j*sin(iAngle)) / (i*i + j*j) );
                }  
            }
        }
    }
}


