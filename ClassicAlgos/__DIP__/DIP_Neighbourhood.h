////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Neighbourhood.h
//
// Class used to manage the pixels in a specific neighbourhood around a pixel.  Note that this
// is primarily used during the filtering process.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef __DIP_NEIGHBOURHOOD_H__
#define __DIP_NEIGHBOURHOOD_H__


// Header files...
#include "DIP_Defs.h"
#include "DIP_Image.h"


// Forward declarations...
class DIP_Filter;


#include <vector>
using namespace std;



class DIP_Neighbourhood
{
    public:

        //
        // Constructor
        //
        DIP_Neighbourhood  ( DIP_Image *               iParentImage,                
                             unsigned int              iWidth, 
                             unsigned int              iHeight, 
                             DIP_FILTER_TYPE           iType,
                             int                       iFilterSubType,
                             vector<double> &          iFilterParameters,
                             DIP_IMAGEBORDER_STRATEGY  iBorderStrategy = BORDER_ZERO );

       ~DIP_Neighbourhood ();


        bool  InitializePosition  (unsigned int iX = 0, unsigned int iY = 0);

        bool  ResetPosition       ();
        bool  IncrementPosition   ();
        bool  IncrementWindowSize ();

        bool  ComputeResults ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oPixelValue );



    private:

        DIP_Neighbourhood (); 

        int  TestWithinRange      (int iIndexValue, int XorY);


        DIP_Image *               _pParentImage;

        int                       _nWindowWidth;
        int                       _nWindowHeight;
        int                       _nRegionWidth;
        int                       _nRegionHeight;
        int                       _nNumberOfPixels;
 
     
        DIP_IMAGEBORDER_STRATEGY  _BorderStrategy; 

        int                       _nCurrentX;
        int                       _nCurrentY;


        vector<DIP_PIXEL_TYPE>*   _NeighbourhoodPixels;

        DIP_Filter *              _pFilter;
        DIP_FILTER_TYPE           _FilterType;


    //
    // Friend classes...
    //
    friend  class  DIP_Filter_Mean;
    friend  class  DIP_Filter_OrderedStat;
    friend  class  DIP_Filter_WeightedSum;
    
};


#endif//__DIP_NEIGHBOURHOOD_H__



