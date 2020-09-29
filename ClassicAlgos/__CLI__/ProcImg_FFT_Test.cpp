////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_FFT_Test.cpp
//
// Small tool used to compute the frequency space of an image
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_ComplexImage.h"
#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_Utils.h"



#include <iostream>
#include <cstdlib>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc != 6 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Pad Image>  <Pad Extra>  <Shift Origin>     " << endl;
        cerr << endl;
        cerr << "Where: <Pad Image> 1 -> true; 2 -> false; pad image with zeros if not a multiple of 2^n                      " << endl;
        cerr << "       <Pad Extra> 1 -> true; 2 -> false; pad image to 2^(n+1) if <Pad Image> is true                        " << endl;
        cerr << "       <Shift Origin> 1 -> true; 2 -> false; multiply by -1^(i + j) to shift origin                          " << endl;
        cerr << endl;
    }
    else
    {
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        bool bPadImage = true;
        if ( atoi ( argv[3] ) != 1  )
            bPadImage = false;
        
        bool bPadExtra = true;
        if ( atoi ( argv[4] ) != 1  )
            bPadExtra = false;
        
        bool bShiftOrigin = true;
        if ( atoi ( argv[5] ) != 1  )
            bShiftOrigin = false;
        
        if ( pImage )
        {
            DIP_ComplexImage * pComplexImage = NULL;
            DIP_Image_Utils::BuildComplexFromImage ( pImage, pComplexImage, bPadImage, bPadExtra );

            if ( pComplexImage )
            {
                cout << "-> Taking forward FFT" << endl;
//                pComplexImage -> ComputeForwardFFT (bShiftOrigin);

                cout << "-> Taking inverse FFT" << endl;
//                pComplexImage -> ComputeInverseFFT (bShiftOrigin);

                DIP_Image * pOutputImage = NULL;
                DIP_Image_Utils::BuildImageFromComplex ( pComplexImage, pOutputImage, (DIP_COMPLEXCONVERT_TYPE)1, false );

                DIP_Image_FileUtils::WritePGMFile ( argv [2], pOutputImage, PGM_BINARY );

                delete pComplexImage;
                delete pOutputImage;
                delete pImage;
            }
        } 
    }

    return 0;
}



