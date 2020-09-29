////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplyHistoTrans.cpp
//
// Small tool used to transform the histograms
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_ProcessUtils.h"
#include "DIP_Histogram.h"


#include <iostream>
#include <cstdlib>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc != 3 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  " << endl;
    }
    else
    {
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        if ( pImage )
        {
            DIP_Image * pModifiedImage = NULL;
            DIP_Image_ProcessUtils::ApplyHistogramEqualization ( pImage, pModifiedImage );
          
            DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );

            delete pModifiedImage;
            delete pImage;
        } 
    }

    return 0;
}



