////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Math_Utils.h
//
// Class used to group together various math utilities.  Note that these functions operate on 
// numbers (including complex values), not images.
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <vector>
using namespace std;


#ifndef __DIP_MATH_UTILS_H__
#define __DIP_MATH_UTILS_H__


class DIP_Math_Utils
{
    public:


        //
        // ComputeWeights: used to compute the weights for a weighted average filter
        //
        static  bool          ComputeWeights ( unsigned int iValue, vector<double> & oWeights );


        //
        // ComputeCenter: used to compute the center position for a set of data
        //
        static  unsigned int  ComputeCenter  ( unsigned int iLength );


        //
        // ComputeDistance: used to find the distance from the origin to a point on the plane.  
        //     Note, that iDoSqrt will take the square root if true and not if false (for efficiency 
        //     if called within a loop).
        //
        static  double        ComputeDistance ( int iX, int iY, bool iDoSqrt=true );  


    private:

};


#endif//__DIP_MATH_UTILS_H__


