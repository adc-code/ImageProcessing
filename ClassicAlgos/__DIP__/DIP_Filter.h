////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter
//
// Class used to manage various types of filters that are applied to a neighbourhood of pixels.
// Note that all neighbourhood based filters are to derive from this class.
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Neighbourhood.h"
#include "DIP_Defs.h"


#ifndef __DIP_FILTER_H__
#define __DIP_FILTER_H__



class DIP_Filter
{
    public:

        DIP_Filter ( DIP_Neighbourhood * iNeighbourhood );
      
        virtual ~DIP_Filter ();

        //
        // ComputeResults...
        // -> Derived classes need to implement this function.  Note that this class is a friend
        //    class to the DIP_Neighbourhood class which will allow it to access all the necessary 
        //    pixel values.  Also, DIP_Neighbourhood will call with function once the data has 
        //    been properly updated.
        // 
        virtual  bool  ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults )    =   0;


    protected:

        DIP_Neighbourhood *  _pNeighbourhood;
};



#endif//__DIP_FILTER_H__



