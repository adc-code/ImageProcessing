////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ComputeHistogram.cpp
//
// Small tool used to compute the histogram of an image and output it to a text file.  The results
// can be used in excel or matlab for futher analysis, or for external documentation.
//
// The format of the data is:
//   - The mean (mu)
//   - The standard deviation (sigma)
//   - The number of bins to expect
//   - The data (one entry per line).
//
// Note that each entry is in the form <key, value>
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Histogram.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


#define  TEXT_MU       "mu       "
#define  TEXT_SIGMA    "sigma    "
#define  TEXT_NUMBINS  "numBins  "


int main ( int argc, char * argv [] )
{
    if ( argc != 4 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output Text File>  <Style>" << endl;
    }
    else
    {
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        int nStyle = atoi ( argv [3] );

        if ( pImage )
        {
            // Get the number of values that a pixel can have; this will be the number of bins
            // in the histogram
            unsigned int nNumBins = pImage -> GetNumValues ();

            // Compute the histogram
            DIP_Histogram histogram ( nNumBins );
            pImage -> ComputeHistogram ( GREY_CHANNEL, histogram );

            if (nStyle == 1)
                histogram.Normalize ();

            // Write out the histogram
            ofstream outputFile ( argv [2] );
            if (outputFile.is_open ())
            {  
                outputFile << TEXT_MU      << histogram.ComputeMean ()      << endl;
                outputFile << TEXT_SIGMA   << histogram.ComputeStdDev ()    << endl;
                outputFile << TEXT_NUMBINS << histogram.GetNumberOfBins ()  << endl;
 
                double dValue = 0;
                for (int i = 0; i < pImage -> GetNumValues (); i++)
                {
                    if ( histogram.GetValue ( i, dValue ) )
                        outputFile << i+1 << "  " << dValue << endl;
                } 
                outputFile << endl;

                outputFile.close ();
            }
                                                   
            delete pImage;
        } 
    }

    return 0;
}


