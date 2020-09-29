////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_OrderStat.h
//
// Class used to manage various types of *Ordered Statistics* filters that are applied to a 
// neighbourhood of pixels.  Note that all neighbourhood based filters are to derive from this 
// class.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Defs.h"
#include "DIP_Filter.h"



#ifndef __DIP_FILTER_ORDEREDSTAT_H__
#define __DIP_FILTER_ORDEREDSTAT_H__



class DIP_Filter_OrderedStat : public DIP_Filter
{
    public:

        DIP_Filter_OrderedStat ( DIP_Neighbourhood *         iNeighbourhood, 
                                 DIP_ORDEREDSTATFILTER_TYPE  iType, 
                                 double                      iParam = 0.0 );

        //
        // ComputeResults...
        // -> Note: uses the values from the neighbourhood to compute the filter
        //    dependent on the required type.  
        // 
        bool  ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults );



    private:

        DIP_ORDEREDSTATFILTER_TYPE  _Type;

        // Note that the parameter can be either 'd' or 'S_max'
        double                      _Param;

};



#endif//__DIP_FILTER_ORDEREDSTAT_H__



