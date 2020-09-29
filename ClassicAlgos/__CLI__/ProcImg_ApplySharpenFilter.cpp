////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplySharpenFilter.cpp
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
    if ( argc < 5 )
    { 
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Window Width>   <Window Height>  [Border Strategy]  [Parameter]" << endl;
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
            /* int pixelValue = 0;
            for (int j = 0; j < pImage -> GetHeight(); j++)
            {
                for (int i = 0; i < pImage -> GetWidth(); i++)
                {
                    pImage -> GetPixel (i, j, pixelValue);
                    cout << pixelValue << "  ";
                }
                cout << endl;
            } */ 

            unsigned int        nWindowWidth    = atoi ( argv [3] );
            unsigned int        nWindowHeight   = atoi ( argv [4] );

            DIP_IMAGEBORDER_STRATEGY borderStrategy = BORDER_ZERO;
            if ( argc > 5 ) 
                borderStrategy = (DIP_IMAGEBORDER_STRATEGY) atoi ( argv [5] );

            double dParameter = 1;
            if ( argc > 6 )
            {
                dParameter = atof ( argv [6] );
            }

            DIP_Image * pModifiedImage = NULL;
            bool bOK = DIP_Image_ProcessUtils::ApplySharpenFilter ( pImage,
                                                                    pModifiedImage,
                                                                    nWindowWidth,
                                                                    nWindowHeight,
                                                                    borderStrategy, 
                                                                    dParameter );
            
            /* for (int j = 0; j < pModifiedImage -> GetHeight(); j++)
            {
                for (int i = 0; i < pModifiedImage -> GetWidth(); i++)
                {
                    pModifiedImage -> GetPixel (i, j, pixelValue);
                    cout << pixelValue << "  ";
                }
                cout << endl;
            } */

            if (!bOK)
            {
                cerr << "ERROR : was unable to compute the sharpen filter" << endl;
            }
            else
            {
             //   DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );
                DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_ASCII ); 
                delete pModifiedImage; 
            }

            delete pImage;
        } 
    } 

    return 0;
}


