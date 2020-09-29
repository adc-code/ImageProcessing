////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Filter_OrderedStat.cpp
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Filter_OrderedStat.h"
#include <cmath>
#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_Filter_OrderedStat::DIP_Filter_OrderedStat ( DIP_Neighbourhood *         iNeighbourhood, 
                                                 DIP_ORDEREDSTATFILTER_TYPE  iType, 
                                                 double                      iParam ) 
               : DIP_Filter ( iNeighbourhood )
{
    cout << "### DIP_Filter_OrderedStat...  " << _Type << endl;

    _Type  = iType;
    _Param = iParam;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ComputeResults...
// -> Under the assumption that the neighbourhood has been sorted
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Filter_OrderedStat::ComputeResults  ( DIP_IMAGE_CHANNEL iChannel, DIP_PIXEL_TYPE & oResults )
{
    bool bRetVal = false;

    if ( _pNeighbourhood )
    {
        if ( _Type == OS_MEDIAN )
        {
            if ( _pNeighbourhood -> _nNumberOfPixels > 0 )
            {
                int nMedianOffset = (_pNeighbourhood -> _nNumberOfPixels - 1) / 2;
                oResults = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ nMedianOffset ];
                bRetVal  = true;
            }
        }        
        else if ( _Type == OS_MAX )
        {
            if ( _pNeighbourhood -> _nNumberOfPixels > 0 )
            {
                // Return the last element, if it exists
                oResults = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].back ();
                bRetVal  = true;
            }
        }
        else if ( _Type == OS_MIN )
        {
            if ( _pNeighbourhood -> _nNumberOfPixels > 0 )
            {
                // Return the first element, if it exists
                oResults = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].front ();
                bRetVal  = true;
            }
        }
        else if ( _Type == OS_MIDPOINT )
        {
            if ( _pNeighbourhood -> _nNumberOfPixels > 0 )
            {
                oResults = (DIP_PIXEL_TYPE) ( _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].front () +
                                              _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].back  () ) / 2;
                bRetVal  = true;
            }
        }
        else if ( _Type == OS_ALPHATRIMMED )
        {
            // d can range from 0 to mn-1
            if ( _Param >= 0 && _Param < (_pNeighbourhood -> _nNumberOfPixels - 1) )
            {
                unsigned int nLowerLimit = (int) _Param / 2;
                unsigned int nUpperLimit = (_pNeighbourhood -> _nNumberOfPixels - 1) - (int) _Param / 2;

                int nRemainingTotal = 0;
                for (unsigned int i = nLowerLimit; i <= nUpperLimit; i++)
                {
                    nRemainingTotal += _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ i ];
                }

                oResults = nRemainingTotal / ( _pNeighbourhood -> _nNumberOfPixels - _Param );
                bRetVal  = true;
            }
        } 
        else if ( _Type == OS_ADAPTIVEMEDIAN )
        {
            // Instead of S_max, the parameter is the max number of iterations where each iteration 
            // increases the window size by one unit in each direction
            if ( _pNeighbourhood -> _nNumberOfPixels > 0 )
            {
                int Smax = _Param; 
              
                // Only have to get the current value once, however the min and max values change as
                // the neighbourhood size increases
 
                DIP_PIXEL_TYPE Zxy = 0;
                _pNeighbourhood -> _pParentImage -> GetValue ( _pNeighbourhood -> _nCurrentX,
                                                               _pNeighbourhood -> _nCurrentY, 
                                                               iChannel,
                                                               Zxy );

//                cout << "   Smax = " << Smax << "   NS = " << _pNeighbourhood -> _nNumberOfPixels 
//                     << "   Zxy = " << curValue << endl;
                for (int i = 1; i <= Smax; i++)
                {
                    DIP_PIXEL_TYPE Zmin = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].front ();
                    DIP_PIXEL_TYPE Zmax = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ].back  ();

                    int nMedianOffset = (_pNeighbourhood -> _nNumberOfPixels - 1) / 2;
                    DIP_PIXEL_TYPE Zmed = _pNeighbourhood -> _NeighbourhoodPixels [ iChannel ][ nMedianOffset ];

                    DIP_PIXEL_TYPE A1 = Zmed - Zmin;
                    DIP_PIXEL_TYPE A2 = Zmed - Zmax;
                
//                    cout << "   i = " << i << "   minValue = " << minValue << "  maxValue = " << maxValue 
//                         << "   medValue = " << medValue << "   A1 = " << A1 << "   A2 = " << A2 << endl;

                    // Note: small change from the book... testing A1 >= 0 instead of A1 > 0...
                    if (A1 >= 0 && A2 < 0)
                    {
                        DIP_PIXEL_TYPE B1 = Zxy - Zmin;
                        DIP_PIXEL_TYPE B2 = Zxy - Zmax;

                        if (B1 > 0 && B2 < 0)
                        {
                            oResults = Zxy;
                            bRetVal  = true;
                            break;
                        }
                        else
                        {
                            oResults = Zmed;
                            bRetVal  = true;
                            break;
                        }
                    }
   
                    // Increase the neighbourhood size by one unit in each direction, which forces the
                    // neighbourhood to be rebuilt and sorted again.

//cout << "  IncrementWindowSize =>   i = " << i << "   " << _pNeighbourhood -> _nCurrentX << "  " << _pNeighbourhood -> _nCurrentY << endl;
                    _pNeighbourhood -> IncrementWindowSize ();
                }

                if (!bRetVal)
                {
                    oResults = Zxy;
                    bRetVal  = true; 
                }
            }
        }
    }

    return bRetVal;
}



