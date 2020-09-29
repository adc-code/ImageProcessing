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
    if ( argc != 5 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <BPP>  <TYPE> " << endl;
        cerr << endl;
        cerr << "   Where <TYPE> => 1 - SIMPLE : division based                                " << endl;
        cerr << "                => 2 - ADVANCED : quantization based                          " << endl;
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
            DIP_IMAGE_BPP             nBPP = (DIP_IMAGE_BPP) atoi ( argv [3] );
            DIP_GREYLEVELCONVERT_TYPE type = (DIP_GREYLEVELCONVERT_TYPE) atoi ( argv [4] ); 

            //
            // Process the image...
            // 
            DIP_Image * pModifiedImage = NULL;
            bool bOK = DIP_Image_ProcessUtils::ApplyChangeBitsPerPixel ( pImage, pModifiedImage, nBPP, type );

            if (!bOK)
            {
                cerr << "ERROR : was unable to change the bits per pixel in the image" << endl;
            }
            else
            {
                DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );
                delete pModifiedImage; 
            }

            delete pImage;
        } 
    } 

    return 0;
}


