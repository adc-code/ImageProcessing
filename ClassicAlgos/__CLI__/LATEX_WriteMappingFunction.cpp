////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LATEX_WriteMappingFunction
//
// Utility class used to output latex friendly code for external documentation
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


#define  PADDING      0.05
#define  PRINT_PREC   5


int main ( int argc, char * argv [] )
{
    if ( argc != 4 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Mapping Data File>  <Width>  <Height>  " << endl;
    }
    else
    {
        ifstream inputFile ( argv [1] );
        double dWidth  = atof ( argv [2] );
        double dHeight = atof ( argv [3] );

        unsigned int nNumValues = 0;
        vector<double>  dXValues;
        vector<double>  dYValues;

        if ( inputFile.is_open () )
        {
            string strToken;
            inputFile >> strToken;
            nNumValues = stoi (strToken);

            unsigned int nCount = 0;
            double dTempValue = 0.0;
            while ( inputFile.eof() == false && nCount < nNumValues)
            {
                inputFile >> strToken;
                dTempValue = stod (strToken);
                dXValues.push_back (dTempValue);
             
                inputFile >> strToken;
                dTempValue = stod (strToken);
                dYValues.push_back (dTempValue);

                nCount ++;
            }

            inputFile.close ();
        }

        if (nNumValues > 0)
        {
            double dGraphWidthScale  = dWidth  * (1 - 2*PADDING);
            double dGraphHeightScale = dHeight * (1 - 2*PADDING);

            double dXOffset = dWidth*PADDING  / dGraphWidthScale; 
            double dYOffset = dHeight*PADDING / dGraphHeightScale;

            cout << "\\psset{ xunit=" << dGraphWidthScale  << "in ,"
                 <<         " yunit=" << dGraphHeightScale << "in }" << endl;

            cout << "\\begin{pspicture}( " << 0 - dXOffset << " , " << 0 - dYOffset << " )"
                 <<                   "( " << 1 + dXOffset << " , " << 1 + dYOffset << " ) "
                 << endl;

            cout << "\\psframe( " << 0 - dXOffset << " , " <<  0 - dYOffset << " )"
                 <<          "( " << 1 + dXOffset << " , " <<  1 + dYOffset << " ) "
                 << endl;

            cout << "\\psframe[linewidth=0pt]( 0, 0 )( 1, 1) " << endl;

            cout << "\\psline[linewidth=0.5pt]";
            for (int i = 0; i < nNumValues; i++)
            {
                double dXValue = dXValues [i];
                double dYValue = dYValues [i];

                // Note: to avoid numbers in scientific notation, just use a tolerance and write zero instead
                if ( dXValue < 0.0001 ) dXValue = 0;
                if ( dYValue < 0.0001 ) dYValue = 0;

                cout << "(" << dXValue << "," << dYValue << ")"; 
            }
            cout << endl;

            cout << "\\end{pspicture}" << endl;
        } 
    }

    return 0;
}



