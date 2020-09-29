////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_WeightedSum.h
//
// Class used to manage various types of *weighted sum* filters that are applied to a 
// neighbourhood of pixels.  Note that all neighbourhood based filters are to derive from this 
// class.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Defs.h"
#include "DIP_Filter.h"


#include <vector>
using namespace std;


#ifndef __DIP_FILTER_WEIGHTEDSUM_H__
#define __DIP_FILTER_WEIGHTEDSUM_H__



class DIP_Filter_WeightedSum : public DIP_Filter
{
    public:

        DIP_Filter_WeightedSum ( DIP_Neighbourhood *         iNeighbourhood, 
                                 DIP_WEIGHTEDSUMFILTER_TYPE  iType, 
                                 vector<double> &            iWeights );

        //
        // ComputeResults...
        // -> Note: uses the values from the neighbourhood to compute the
        //    mean dependent on the required type.  If the type is contraharmonic
        //    it will use the Q value as well.
        // 
        bool  ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults );



    private:

        DIP_WEIGHTEDSUMFILTER_TYPE  _Type;
        vector<double>              _Weights;

        
        void  ComputeSobelCoefs  ( double iAngle );
};



#endif//__DIP_FILTER_WEIGHTEDSUM_H__



