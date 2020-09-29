////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ComputeFreqSpace.cpp
//
// Small tool used to compute the frequency space of an image
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_ComplexImage.h"
#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_Utils.h"
//#include "DIP_Image_ProcessUtils.h"
//#include "DIP_Math_ComplexNum.h"
//#include "DIP_Math_ComplexSet.h"



#include <iostream>
#include <cstdlib>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc < 3 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Type>  [Channel]  " << endl;
        cerr << endl;
        cerr << "Where: <Type> : 1 -> Real values "                                                   << endl;
        cerr << "                2 -> Imaginary values "                                              << endl;
        cerr << "                3 -> Magnitude values "                                              << endl;
        cerr << "                4 -> Phase values "                                                  << endl;
        cerr << endl;
    }
    else
    {
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        DIP_COMPLEXCONVERT_TYPE complexConvertType = (DIP_COMPLEXCONVERT_TYPE) atoi ( argv[3] );
        
        if ( pImage )
        {
            DIP_ComplexImage * pComplexImage = NULL;
            DIP_Image_Utils::BuildComplexFromImage ( pImage, pComplexImage );

            if ( pComplexImage )
            {
                pComplexImage -> ComputeForwardFFT ();

                DIP_Image * pOutputImage = NULL;
                DIP_Image_Utils::BuildImageFromComplex ( pComplexImage, pOutputImage, complexConvertType, true );

                DIP_Image_FileUtils::WritePGMFile ( argv [2], pOutputImage, PGM_BINARY );

                delete pComplexImage;
                delete pOutputImage;
                delete pImage;
            }
        } 
    }

    return 0;
}



