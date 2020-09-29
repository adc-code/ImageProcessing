////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplySpatialFilter.cpp
//
// Small utility used to modify the number of bits per pixel
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_ProcessUtils.h"
#include "DIP_Neighbourhood.h"


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc < 7 )
    { 
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Filter Type>  <Filter SubType>  <Window Width>   <Window Height>  [Border Strategy]  [Parameter List]" << endl;
        cerr << endl;
        cerr << "   Where valid values for <Filter Type> and <Filter SubType> are: " << endl;
        cerr << "         <Filter Type> : 1  =>  Mean Filter                       " << endl;
        cerr << "               <Filter SubType> : 1  =>  Arithmetic               " << endl;
        cerr << "               <Filter SubType> : 2  =>  Geometric                " << endl;
        cerr << "               <Filter SubType> : 3  =>  Harmonic                 " << endl;
        cerr << "               <Filter SubType> : 4  =>  Contraharmonic           " << endl;
        cerr << "         <Filter Type> : 2  =>  Ordered Statistics Filter         " << endl;
        cerr << "               <Filter SubType> : 1  =>  Median                   " << endl;
        cerr << "               <Filter SubType> : 2  =>  Max                      " << endl;
        cerr << "               <Filter SubType> : 3  =>  Min                      " << endl;
        cerr << "               <Filter SubType> : 4  =>  Mid point                " << endl;
        cerr << "               <Filter SubType> : 5  =>  Alpha trimmed mean       " << endl;
        cerr << "         <Filter Type> : 3  =>  Weighted Sum Filter               " << endl;
        cerr << "               <Filter SubType> : 1  =>  Average                  " << endl;
        cerr << "               <Filter SubType> : 2  =>  Weighted Average         " << endl;
        cerr << "               <Filter SubType> : 3  =>  Laplacian                " << endl;
        cerr << "               <Filter SubType> : 4  =>  Sobel (horizontal)       " << endl;
        cerr << "               <Filter SubType> : 5  =>  Sobel (vertical)         " << endl;
        cerr << "               <Filter SubType> : 6  =>  Sobel (diagonal + 45)    " << endl;
        cerr << "               <Filter SubType> : 7  =>  Sobel (diagonal - 45)    " << endl;
        cerr << endl;
    }
    else
    {
        //
        // Load the image...
        //
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        if ( pImage )
        {
            int pixelValue = 0;
            /* for (int j = 0; j < pImage -> GetHeight(); j++)
            {
                for (int i = 0; i < pImage -> GetWidth(); i++)
                {
                    pImage -> GetPixel (i, j, pixelValue);
                    cout << pixelValue << "  ";
                }
                cout << endl;
            } */ 

            int                 nFilterType     = atoi ( argv [3] );
            int                 nFilterSubType  = atoi ( argv [4] );
            unsigned int        nWindowWidth    = atoi ( argv [5] );
            unsigned int        nWindowHeight   = atoi ( argv [6] );

            DIP_IMAGEBORDER_STRATEGY borderStrategy = BORDER_ZERO;
            if ( argc > 7 ) 
                borderStrategy = (DIP_IMAGEBORDER_STRATEGY) atoi ( argv [7] );

            vector <double>  dParameters;
            if ( argc > 8 )
            {
                for (int i = 8; i < argc; i++)
                {
                    dParameters.push_back ( atof ( argv [i] ) );
                }
            }

            bool bOK = false;
            DIP_Image * pModifiedImage = NULL;

            if ( nFilterType == 1 )
            { 
                DIP_MEANFILTER_TYPE nMeanFilterType = (DIP_MEANFILTER_TYPE) nFilterSubType;
                double dQValue = 0.0;
                if ( dParameters.size () > 0 )
                    dQValue = dParameters [0];

                bOK = DIP_Image_ProcessUtils::ApplyMeanFilter ( pImage,
                                                                pModifiedImage,
                                                                nMeanFilterType,
                                                                nWindowWidth,
                                                                nWindowHeight,
                                                                borderStrategy,
                                                                dQValue );
            }
            else if ( nFilterType == 2 )
            {
                DIP_ORDEREDSTATFILTER_TYPE nOrderedStatFilterType = (DIP_ORDEREDSTATFILTER_TYPE) nFilterSubType;
                double dDValue = 0.0;
                if ( dParameters.size () > 0 )
                    dDValue = dParameters [0];

                bOK = DIP_Image_ProcessUtils::ApplyOrderedStatFilter ( pImage, 
                                                                       pModifiedImage, 
                                                                       nOrderedStatFilterType,
                                                                       nWindowWidth, 
                                                                       nWindowHeight, 
                                                                       borderStrategy,
                                                                       dDValue );
            }
            else if ( nFilterType == 3 )
            {
                DIP_WEIGHTEDSUMFILTER_TYPE nWeightedSumFilterType = (DIP_WEIGHTEDSUMFILTER_TYPE) nFilterSubType;

                bOK = DIP_Image_ProcessUtils::ApplyWeightedSumFilter ( pImage,
                                                                       pModifiedImage,
                                                                       nWeightedSumFilterType,
                                                                       nWindowWidth,
                                                                       nWindowHeight,
                                                                       borderStrategy,
                                                                       dParameters );
            }

          //  cout << "    " << endl;
            for (int j = 0; j < pModifiedImage -> GetHeight(); j++)
            {
                for (int i = 0; i < pModifiedImage -> GetWidth(); i++)
                {
                    pModifiedImage -> GetPixel (i, j, pixelValue);
      //              cout << pixelValue << "  ";
                }
        //        cout << endl;
            } 

            if (!bOK)
            {
                cerr << "ERROR : was unable to compute the mean filter" << endl;
            }
            else
            {
                //DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );
                DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_ASCII ); 
                delete pModifiedImage; 
            }

            delete pImage;
        } 
    } 

    return 0;
}


