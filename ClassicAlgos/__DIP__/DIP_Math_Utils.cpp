////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Math_Utils.cpp
//
// Class used to group together various math utilities.
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Math_Utils.h"
//#include "DIP_Math_ComplexNum.h"

#include <cmath>
#include <complex>
#include <iostream>
using namespace std;




////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeWeights
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Math_Utils::ComputeWeights ( unsigned int iValue, vector<double>&  oWeights )
{
    bool bResults = false;

    oWeights.resize ( iValue );

    unsigned int nCentralValue = ComputeCenter ( iValue );
   
    for (unsigned int i = 0; i < iValue; i++)
    {
        if ( i == 0 )
        {
            oWeights [ i ] = 1;
        }
        else if ( i <= nCentralValue )
        {
            oWeights [ i ] = oWeights [ i-1 ] + 1;
        }
        else
        {
            oWeights [ i ] = oWeights [ i-1 ] - 1;
        }
    }

    if ( oWeights.size() > 0 )
       bResults = true; 

    return bResults;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeCenter
//
////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DIP_Math_Utils::ComputeCenter ( unsigned int iLength )
{
    unsigned int nResults = 0;

    int nCentralValue = (iLength - 1) / 2;

    if ( nCentralValue >= 0 )
        nResults = (unsigned int) nCentralValue;
        
    return nResults;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeDistance
//
////////////////////////////////////////////////////////////////////////////////////////////////////
double DIP_Math_Utils::ComputeDistance ( int iX, int iY, bool iDoSqrt )
{
    if ( iDoSqrt )
        return sqrt ( iX*iX + iY*iY );
    else
        return ( iX*iX + iY*iY );
}



