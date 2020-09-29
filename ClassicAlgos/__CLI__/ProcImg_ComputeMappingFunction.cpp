////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ProcImg_ComputeMappingFunction.cpp
//
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_MappingFunction.h"


#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



int main ( int argc, char * argv [] )
{
    if ( argc < 3 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Output Txt File>  <Type>  [Parameters... ]" << endl;
        cerr << endl;
        cout << "  Where <Type> = 1  Identity transformation; Parameters: not used                  " << endl;
        cout << "                 2  Negative transformation; Parameters: not used                  " << endl;
        cout << "                 3  Log based e; Parameters: max value                             " << endl;
        cout << "                 4  Log based 10; Parameters: max value                            " << endl;
        cout << "                 5  Base e exponential; Parameters: max value                      " << endl;
        cout << "                 6  Base 10 exponential; Parameters: max value                     " << endl;
        cout << "                 7  Power; Parameters: 1 - gamma                                   " << endl;
        cout << "                 8  Piecewise; Parameters: { x, y } pairs for intermediate points  " << endl; 
        cout << "                 9  Sigmoidal; Parameters: 1 - alpha, 2 - mu, 3 - lower, 4 - upper " << endl; 
        cout << endl;  
    }
    else
    {
        DIP_MAPPING_FUNCTIONTYPE mapFuncType = (DIP_MAPPING_FUNCTIONTYPE) atoi ( argv [2] );

        vector<double>  dParameters;   
        if ( mapFuncType == MAPFUNC_LOG_E || mapFuncType == MAPFUNC_LOG_10 ||
             mapFuncType == MAPFUNC_EXP_E || mapFuncType == MAPFUNC_EXP_10 ||
             mapFuncType == MAPFUNC_POWER )
        {
            double dMaxValue = 1.0;
            if ( argc > 3 )
                dMaxValue = atof ( argv [3] );

            dParameters.push_back ( dMaxValue );
        }
        else if ( mapFuncType == MAPFUNC_POWER)
        {
            double dGamma = 1;
            if ( argc > 4 )
                dGamma = atof ( argv [4] );

            dParameters.push_back ( dGamma );
        }
        else if ( mapFuncType == MAPFUNC_SIGMOIDAL )
        {
            if ( argc > 6 )
            {
                for (int i = 3; i <= 6; i++)
                    dParameters.push_back ( atof ( argv [i] ) );
            }
        }
        else if ( mapFuncType == MAPFUNC_PIECEWISE )
        {
            if ( argc > 4 && argc % 2 == 1 )
            {
                for (int i = 3; i < argc; i += 2)
                {
                    dParameters.push_back ( atof ( argv [i] ) );
                    dParameters.push_back ( atof ( argv [i+1] ) );
                }
            }
        }


         DIP_MappingFunction  mappingFunction ( mapFuncType, dParameters );

         ofstream outputFile ( argv [1] );
         if (outputFile.is_open ())
         {
             vector <double>  xValues;
             vector <double>  yValues;
             for (double i = 0; i <= 1.001; i += 0.01)
             {
                 double dValue = 0;
                 mappingFunction.Evaluate ( i, dValue );

                 xValues.push_back (i);
                 yValues.push_back (dValue);
             }

             outputFile << xValues.size () << endl;
             for (int i = 0; i < xValues.size (); i++)
             {
                 outputFile << xValues [i]  << "   " << yValues [i] <<  endl;
             }

             outputFile.close ();
         }
    }

    return 0;
}



