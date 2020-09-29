////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_Mean.h
//
// Class used to manage various types of *Mean* filters that are applied to a neighbourhood of 
// pixels.  Note that all neighbourhood based filters are to derive from this class.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Defs.h"
#include "DIP_Filter.h"



#ifndef __DIP_FILTER_MEAN_H__
#define __DIP_FILTER_MEAN_H__


/*
enum DIP_MEAN_TYPE
{
    MEAN_ARITHMETIC,
    MEAN_GEOMETRIC,
    MEAN_HARMONIC,
    MEAN_CONTRAHARMONIC
};*/



class DIP_Filter_Mean : public DIP_Filter
{
    public:

        DIP_Filter_Mean ( DIP_Neighbourhood *  iNeighbourhood, 
                          DIP_MEANFILTER_TYPE  iType, 
                          double               iQ = 0.0 );

        //
        // ComputeResults...
        // -> Note: uses the values from the neighbourhood to compute the
        //    mean dependent on the required type.  If the type is contraharmonic
        //    it will use the Q value as well.
        // 
        bool  ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults );



    private:

        DIP_MEANFILTER_TYPE  _Type;
        double               _dQValue;

};



#endif//__DIP_FILTER_MEAN_H__



