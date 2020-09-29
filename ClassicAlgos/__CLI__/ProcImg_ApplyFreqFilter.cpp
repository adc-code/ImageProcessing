////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplyFreqFilter.cpp
//
// Small tool used to compute the frequency space of an image
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_MathUtils.h"
#include "DIP_Image_ProcessUtils.h"


#include <iostream>
#include <cstdlib>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc < 5 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Type>  <Cut off Freq>  [N Value]  " << endl;
    }
    else
    {
        cout << "have enough params" << endl;

        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        cout << "have picture" << endl;

        DIP_FREQFILTER_TYPE filterType = (DIP_FREQFILTER_TYPE) atoi (argv[3]);

        double dCutOffFreqPercent = atof (argv[4]);

        int nNValue = 1;
        if (argc == 6)
           nNValue = atoi (argv[5]);

        if ( pImage )
        {
            DIP_Image * pFilteredImage = NULL;
            DIP_Image_ProcessUtils::ApplyFreqDomainFilter ( pImage,
                                                            pFilteredImage,
                                                            filterType,
                                                            dCutOffFreqPercent,
                                                            nNValue );

            cout << "done filter" << endl;
            DIP_Image_FileUtils::WritePGMFile ( argv [2], pFilteredImage, PGM_BINARY );

            if ( pFilteredImage )
                delete pFilteredImage;

            delete pImage;
        } 
    }

    return 0;
}



