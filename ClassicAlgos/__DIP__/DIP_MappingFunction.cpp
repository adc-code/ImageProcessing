////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_MappingFunction
//
// Implementation of the mapping functions
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Defs.h"
#include "DIP_MappingFunction.h"

#include <cmath>

#include <iostream>
using namespace std;



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_MappingFunction::DIP_MappingFunction ( DIP_MAPPING_FUNCTIONTYPE iType )
{
    _Type = iType;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_MappingFunction::DIP_MappingFunction ( DIP_MAPPING_FUNCTIONTYPE iType, vector<double> & iParams )
{
    _Type       = iType;
    _Parameters = iParams;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Copy Constructor
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_MappingFunction::DIP_MappingFunction ( const DIP_MappingFunction & iMapFunc )
{
    _Type       = iMapFunc._Type;
    _Parameters = iMapFunc._Parameters;
    _LUT        = iMapFunc._LUT;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Assignment Operator
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_MappingFunction & DIP_MappingFunction::operator= ( const DIP_MappingFunction & iMapFunc )
{
    _Type       = iMapFunc._Type;
    _Parameters = iMapFunc._Parameters;
    _LUT        = iMapFunc._LUT;

    return *this;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetFunctionType
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_MAPPING_FUNCTIONTYPE DIP_MappingFunction::GetFunctionType ()
{
    return _Type;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// GetParameters
//      
////////////////////////////////////////////////////////////////////////////////////////////////////
vector<double> & DIP_MappingFunction::GetParameters ()
{
    return _Parameters;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Evaluate
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_MappingFunction::Evaluate (double iX, double & oY)
{
    bool bRetVal = false;

    // First check to see if input is within the limits
    if ( iX >= 0.0 && iX <= 1.0 + DIP_MATH_EPS )
    {
        if ( _Type == MAPFUNC_IDENTITY )
        {
            // s = r 
            oY = iX;
        }
        else if ( _Type == MAPFUNC_NEGATIVE )
        {
            // s = max - r; note the functions are defined so that max is 1
            oY = 1.0 - iX;

            bRetVal = true;
        }
        else if ( _Type == MAPFUNC_LOG_E )
        {
            // s = c ln ( 1 + r ); note that since the function is bounded to [0, 1], then
            // the coefficent c is 1 / log (2).  The cmath header has a constant defined for
            // this value.

            double dAlpha = 1.0;
            if ( _Parameters.size () > 0 )
                dAlpha = _Parameters [0];

            double c = 1 / log ( 1 + dAlpha );

            oY =  c * log ( 1 + dAlpha * iX );

            bRetVal = true;
        }
        else if ( _Type == MAPFUNC_LOG_10 )
        {
            // s = c log ( 1 + r )
            double dAlpha = 1.0;
            if ( _Parameters.size () > 0 )
                dAlpha = _Parameters [0];

            double c = 1 / log10 ( 1 + dAlpha );

            oY =  c * log10 ( 1 + dAlpha * iX );

            bRetVal = true;
        }
        else if ( _Type == MAPFUNC_EXP_E )
        {
            // s = e ^ ( c r ) - 1
            double dAlpha = 1.0;
            if ( _Parameters.size () > 0 )
                dAlpha = _Parameters [0];

            double c = log ( 1 + dAlpha );

            oY = (exp ( c * iX ) - 1) / dAlpha;

            bRetVal = true;
        }
        else if ( _Type == MAPFUNC_EXP_10 )
        {
            // s = 10 ^ ( c r ) - 1
            double dAlpha = 1.0;
            if ( _Parameters.size () > 0 )
                dAlpha = _Parameters [0];

            double c = log10 ( 1 + dAlpha );

            oY = (pow ( 10.0, c * iX ) - 1) / dAlpha;

            bRetVal = true;
        }
        else if ( _Type == MAPFUNC_POWER )
        {
            // s = c r ^ gamma
            if ( _Parameters.size () > 0 )
            {
                oY = pow ( iX, _Parameters [0] );

                bRetVal = true;
            }
        }
        else if ( _Type == MAPFUNC_PIECEWISE )
        {
            // linear interpolation between points
            int nSize = _Parameters.size ();

            if (nSize >= 4 && nSize % 2 == 0)
            {
                int nIndex = -1;
                for (int i = 0; i < nSize-3; i+=2)
                {
                    if ( iX >= _Parameters [i] && iX <= (_Parameters [i+2]+DIP_MATH_EPS) )
                    {
                        nIndex = i;
                        break;
                    }
                }

                if (nIndex != -1)
                {
                    double t = (iX - _Parameters [nIndex]) / 
                               (_Parameters [nIndex+2] - _Parameters [nIndex]);

                    oY = (_Parameters [nIndex+3] - _Parameters [nIndex+1]) * t + _Parameters [nIndex+1];
                }
            }
        }
        else if ( _Type == MAPFUNC_SIGMOIDAL )
        {
            // s = (B - A) * (1 / ( 1 + exp ( -alpha(r - m) ) ) ) + A
            int nSize = _Parameters.size ();
          
            if (nSize > 3)
            {
                double dDemoninator = 1 + exp ( -1 * _Parameters [0] * ( iX - _Parameters [1] ) );
                oY = (1 / dDemoninator) * (_Parameters [3] - _Parameters [2]) + _Parameters [2];
            }
        }
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeLUT
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_MappingFunction::ComputeLUT (unsigned int iXScaling, unsigned int iYScaling)
{
    bool bRetVal = false;

    if ( iXScaling > 0 && iYScaling > 0 )
    {
        _LUT.clear ();
        _LUT.resize ( iXScaling );

        for (int i = 0; i < iXScaling; i++)
        {
            double dScaledX = (double) i / (double) iXScaling;
            double dScaledY = -1.0;

            Evaluate ( dScaledX, dScaledY );

            dScaledY *= (iYScaling - 1);

            _LUT [i] = dScaledY;
        }

        bRetVal = true;
    }

    return bRetVal;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// EvalutateUsingLUT
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_MappingFunction::EvaluateUsingLUT (unsigned int iX, DIP_PIXEL_TYPE & oY)
{
    bool bRetVal = false;

    if ( iX < _LUT.size () )
    {
        oY = _LUT [ iX ];

        bRetVal = true; 
    }

    return bRetVal;
}


