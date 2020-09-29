////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplyChangeBitsPerPixel.cpp
//
// Small utility used to modify the number of bits per pixel
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_ProcessUtils.h"


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc != 6 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <New Width>  <New Height>  <Type>  " << endl;
        cerr << endl;
        cerr << "    Where: <Type> = 1  =>  Using Nearest neighbour       " << endl;
        cerr << "    Where: <Type> = 2  =>  Using Bilinear interpolation  " << endl;
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
            unsigned int        nNewWidth    = atoi ( argv [3] );
            unsigned int        nNewHeight   = atoi ( argv [4] );
            DIP_IMGSCALING_TYPE nScalingType = (DIP_IMGSCALING_TYPE) atoi ( argv [5] );

            //
            // Process the image...
            // 
            DIP_Image * pModifiedImage = NULL;
            bool bOK = DIP_Image_ProcessUtils::ApplyScaleTransformation ( pImage, 
                                                                          pModifiedImage, 
                                                                          nNewWidth,
                                                                          nNewHeight,
                                                                          nScalingType );

            if (!bOK)
            {
                cerr << "ERROR : was unable to resize the image" << endl;
            }
            else
            {
                DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );
                //DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_ASCII );
                delete pModifiedImage; 
            }

            delete pImage;
        } 
    } 

    return 0;
}


