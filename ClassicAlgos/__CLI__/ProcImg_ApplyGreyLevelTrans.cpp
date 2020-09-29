////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ApplyGreyLevelTrans.cpp
//
// Small tool used to apply different grey level transformations on an image
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"
#include "DIP_Image_ProcessUtils.h"
#include "DIP_MappingFunction.h"


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc < 3 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Image File>  <Output File>  <Type>  [Parameters] " << endl;
        cerr << endl;
        cout << "  Where <Type> = 1  Identity transformation; Parameters: not used                          " << endl;
        cout << "                 2  Negative transformation; Parameters: not used                          " << endl;
        cout << "                 3  Log based e; Parameters: 1 - max value (default 255 if missing)        " << endl;
        cout << "                 4  Log based 10; Parameters: 1 - max value (default 255 if missing)       " << endl;
        cout << "                 5  Base e exponential; Parameters: 1 - max value (default 255 if missing) " << endl;
        cout << "                 6  Base 10 exponential; Parameters: 1 - max value (default 255 if missing)" << endl;
        cout << "                 7  Power; Parameters: 1 - gamma (default 1 if missing                     " << endl;
        cout << "                 8  Piecewise; Parameters: { x, y } pairs for intermediate points          " << endl;
        cout << "                 9  Sigmoidal; Parameters: 1 - alpha, 2 - mu, 3 - lower, 4 - upper         " << endl;

    }
    else
    {
        DIP_Image * pImage = NULL;
        DIP_Image_FileUtils::ReadPGMFile ( argv [1], pImage );

        if ( pImage )
        {
            DIP_MAPPING_FUNCTIONTYPE mapFuncType = (DIP_MAPPING_FUNCTIONTYPE) atoi ( argv [3] );

            vector <double>  dParameters;

            if ( mapFuncType == MAPFUNC_LOG_E || mapFuncType == MAPFUNC_LOG_10 ||
                 mapFuncType == MAPFUNC_EXP_E || mapFuncType == MAPFUNC_EXP_10 )
            {
                double dMaxValue = 255;
                if ( argc > 4 )
                    dMaxValue = atoi ( argv [4] );

                dParameters.push_back ( dMaxValue );
            }
            else if (mapFuncType == MAPFUNC_POWER)
            {
                double dGamma = 1;
                if ( argc > 4 )
                    dGamma = atof ( argv [4] );

                dParameters.push_back ( dGamma );
            }
            else if (mapFuncType == MAPFUNC_PIECEWISE)
            {
                unsigned int nStartIndex = 4;
                unsigned int nEndIndex   = argc-1;
                if ( nStartIndex < nEndIndex && argc % 2 == 0 )
                {
                    for (int i = nStartIndex; i <= nEndIndex; i++)
                    {
                        dParameters.push_back ( atof ( argv [i] ) );
                    }
                }
            }
            else if ( mapFuncType == MAPFUNC_SIGMOIDAL )
            {   
                if ( argc > 7 )
                {   
                    for (int i = 4; i <= 7; i++)
                        dParameters.push_back ( atof ( argv [i] ) );
                }
            }
            

            DIP_MappingFunction  mappingFunction ( mapFuncType, dParameters );

            DIP_Image * pModifiedImage = NULL;
            DIP_Image_ProcessUtils::ApplyGreyLevelTransformation ( pImage, pModifiedImage, mappingFunction );

            DIP_Image_FileUtils::WritePGMFile ( argv [2], pModifiedImage, PGM_BINARY );

            if ( pModifiedImage )
                delete pModifiedImage;

            delete pImage;
        } 
    }

    return 0;
}


