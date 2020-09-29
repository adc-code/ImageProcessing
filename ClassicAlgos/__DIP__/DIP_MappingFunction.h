////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_MappingFunction.h
//
// Class used to manage mapping functions which are used for the various grey level transformations.  
// The mathematics with grey level transformations is to simply map one grey level to another grey 
// level; that is all values stay within the a limited set of grey levels.  Therefore, the functions 
// are defined on the domain [0, 1], and also the output is bound to [0, 1] (i.e. are normalized).  
//
// The overall flow is as follows... 
//
//                                  Function Type
//                                       and
//                                    parameters
//                                        |
//                                        V
//                                   +----------+
//                       Input       | Mapping  |       Output
//                       Pixel ----->| Function |-----> Pixel
//                      Values       +----------+       Values
//
//
// There are a few supported types of mapping functions:
//  - identity : mainly used to verify that the code is working correctly
//  - negative : finds the inverse image
//  - logarithmic : uses the logarithm function to increase the values (particularly the lower ones)
//  - exponential : uses the exponential function to decrease the values (particularly the upper ones)
//  - power : depending on the supplied parameter can increase of decrease the values; also referred
//            to as gamma correction
//  - piecewise : linear interpolation between the supplied points 
//  - sigmoidal : use an S shaped curve which is created on the supplied parameters (median value,
//                spread of data, lower and upper limits).
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"


#include <vector>
using namespace std;


#ifndef __DIP_MAPPINGFUNCTION_H__
#define __DIP_MAPPINGFUNCTION_H__


enum DIP_MAPPING_FUNCTIONTYPE
{
    MAPFUNC_IDENTITY  =  1,
    MAPFUNC_NEGATIVE  =  2,
    MAPFUNC_LOG_E     =  3,
    MAPFUNC_LOG_10    =  4,
    MAPFUNC_EXP_E     =  5,
    MAPFUNC_EXP_10    =  6,
    MAPFUNC_POWER     =  7,
    MAPFUNC_PIECEWISE =  8,
    MAPFUNC_SIGMOIDAL =  9
};


class DIP_MappingFunction
{
    public:

        //
        // Constructors
        // 
        DIP_MappingFunction ( DIP_MAPPING_FUNCTIONTYPE  iType );
        DIP_MappingFunction ( DIP_MAPPING_FUNCTIONTYPE  iType, vector<double> & iParams );
        DIP_MappingFunction ( const DIP_MappingFunction & iMappingFunc );

        //
        // Overloaded operators
        //
        DIP_MappingFunction &   operator =      ( const DIP_MappingFunction & iMathFunc );

        //
        // Get data...
        //
        DIP_MAPPING_FUNCTIONTYPE  GetFunctionType  ();
        vector<double> &          GetParameters    ();


        //
        // Evaluate the function
        //
        bool   Evaluate   (double iX, double & oY);


        //
        // Look up table (LUT) related functions
        //
        bool   ComputeLUT        (unsigned int iXScaling, unsigned int iYScaling);
        bool   EvaluateUsingLUT  (unsigned int iX, DIP_PIXEL_TYPE & oY);



    private:

        //
        // Default constructor...
        // note: is private so the specified constructor is called.
        //
        DIP_MappingFunction ();


        //
        // Data members
        //
        DIP_MAPPING_FUNCTIONTYPE   _Type;
        vector<double>             _Parameters;

        vector<DIP_PIXEL_TYPE>     _LUT;
};


#endif //__DIP_MAPPINGFUNCTION_H__



