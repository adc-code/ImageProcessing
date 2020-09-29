////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_Mean.cpp
//
// Class used to manage various types of *Mean* filters that are applied to a neighbourhood of 
// pixels.  Note that all neighbourhood based filters are to derive from this class.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Filter_Mean.h"
#include <cmath>
#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_Filter_Mean::DIP_Filter_Mean ( DIP_Neighbourhood *  iNeighbourhood, 
                                   DIP_MEANFILTER_TYPE  iType, 
                                   double iQ ) 
               : DIP_Filter ( iNeighbourhood )
{
    _Type    = iType;
    _dQValue = iQ;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeResults
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Filter_Mean::ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults )
{
    bool bRetVal = false;

    if ( _pNeighbourhood )
    {
        if ( _Type == MEAN_ARITHMETIC )
        {
            double dTotal = 0.0;
            for (int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++)
            {
                dTotal += _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ];

                //cout << "## _pNeighbourhood -> _NeighbourhoodPixels [0][" << i << "] = " 
                //     << _pNeighbourhood -> _NeighbourhoodPixels [0][i] << "    "
                //     << dTotal << endl;
            }

            oResults = dTotal / (double) _pNeighbourhood -> _nNumberOfPixels;
 
            //cout << "## oResults = " << oResults << endl;

            bRetVal = true;
        }        
        else if ( _Type == MEAN_GEOMETRIC )
        {
            double dTotal = 1.0;
 
            for (int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++)
                dTotal *= ( _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ] + 1 );

            oResults = ( pow ( dTotal, 1.0 / (double) _pNeighbourhood -> _nNumberOfPixels ) - 1 );

            bRetVal = true;
        }
        else if ( _Type == MEAN_HARMONIC )
        {
            double dTotal = 0.0;
            for (int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++)
                dTotal += 1.0 / ( (double) _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ] + 1 );

            oResults = ( (double) _pNeighbourhood -> _nNumberOfPixels / dTotal ) - 1;

            bRetVal = true;
        }
        else if ( _Type == MEAN_CONTRAHARMONIC )
        {
            double dNumerator   = 0.0;
            double dDenominator = 0.0;

            for (int i = 0; i < _pNeighbourhood -> _nNumberOfPixels; i++)
            {
                dNumerator   += pow ( _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ] + 1, _dQValue+1 );
                dDenominator += pow ( _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ] + 1, _dQValue );
            }

            if ( dDenominator > DIP_MATH_EPS )
                oResults = ( dNumerator / dDenominator ) - 1;

            bRetVal = true;
        } 
    }

    return bRetVal;
}



