////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LATEX_WriteHistogram
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
#define  BAR_SPACE    0.005


int main ( int argc, char * argv [] )
{
    if ( argc != 4 ) 
    {  
        cerr << "ERROR : Usgage " << argv [0] << "  <Histogram Data File>  <Width>  <Height>  " << endl;
    }
    else
    {
        ifstream inputFile ( argv [1] );
        double dWidth  = atof ( argv [2] );
        double dHeight = atof ( argv [3] );

        double dMean   = 0;
        double dStdDev = 0;
        unsigned int nNumBins = 0;
        vector<double>  histogramData;

        string strToken;
        if ( inputFile.is_open () )
        {
            // For all entries read the data twice... throw out the first entry (the key)...
            inputFile >> strToken;
            inputFile >> strToken;
            dMean = stod (strToken);

            inputFile >> strToken;
            inputFile >> strToken;
            dStdDev = stod (strToken);

            inputFile >> strToken;
            inputFile >> strToken;
            nNumBins = stoi (strToken);

            double dData = 0;
            unsigned int nElementCount = 0;
            while ( inputFile.eof() == false && nElementCount < nNumBins)
            {
                inputFile >> strToken;
                inputFile >> strToken;

                if ( !strToken.empty() )
                {
                    dData = stod (strToken);
                    histogramData.push_back (dData);

                    nElementCount++;
                }
            }

            inputFile.close ();
        }

        nNumBins = histogramData.size (); 
        if (nNumBins > 0)
        {
            double dGraphWidthScale  = dWidth  * (1 - 2*PADDING) / nNumBins;
            double dGraphHeightScale = dHeight * (1 - 5*PADDING);

            double dXOffset  = dWidth*PADDING / dGraphWidthScale; 
            double dYOffset  = dHeight*PADDING / dGraphHeightScale;
            double dBarSpace = dWidth*BAR_SPACE / dGraphWidthScale;

            cout << "\\psset{ xunit=" << dGraphWidthScale  << "in ,"
                 <<         " yunit=" << dGraphHeightScale << "in }" << endl;

            cout << "\\begin{pspicture}( " << -dXOffset           << " , " << -4 * dYOffset  << " )"
                 <<                   "( " << nNumBins + dXOffset << " , " <<  1 + dYOffset << " ) "
                 << endl;

            cout << "\\psframe( " << -dXOffset           << " , " << -4 * dYOffset  << " )"
                 <<          "( " << nNumBins + dXOffset << " , " <<  1 + dYOffset << " ) "
                 << endl;

            cout << "\\psframe[linewidth=0pt]( 0, 0 )( " << nNumBins << " , 1) " << endl;

            for (int i = 0; i <= 10; i++)
            {
                cout << "\\psline[linewidth=0pt]( " << 0        << " , " << i * 0.1 << " )" 
                     <<                        "( " << nNumBins << " , " << i * 0.1 << " ) " << endl;
            }

            int nStyle = 1;
            for (int i = 0; i < nNumBins; i++)
            {
                double dValue = histogramData [i];

                // Note: to avoid numbers in scientific notation, just use a tolerance and write zero instead
                if ( dValue < 0.0001 ) dValue = 0;

                if ( nStyle == 1 )
                {
                    cout << "\\psframe[linewidth=0pt,fillstyle=solid,fillcolor=black]"
                         << "( " <<   i + dBarSpace << " , " <<    0   << " ) " 
                         << "( " << (i+1)-dBarSpace << " , " << dValue << " ) "
                         << endl;
                }
                else if ( nStyle == 2 )
                {
                    cout << "\\psline[linewidth=0.5pt]"
                         << "( " << i << " , " <<    0   << " ) " 
                         << "( " << i << " , " << dValue << " ) "
                         << endl;
                }

                cout << "\\newrgbcolor{newgray}{ " << double (i) / double (nNumBins-1) << "  "
                                                   << double (i) / double (nNumBins-1) << "  "
                                                   << double (i) / double (nNumBins-1) << " }" << endl;
                
                cout << "\\psframe[linewidth=0pt,linecolor=newgray,fillstyle=solid,fillcolor=newgray]"
                     << "( " <<   i   << " , " << -0.5 * dYOffset << " ) " 
                     << "( " << (i+1) << " , " << -1.5 * dYOffset << " ) " 
                     << endl;
            }

            cout << "\\psframe[linewidth=0.5pt,linecolor=black]"
                 << "( " <<     0    << " , " << -0.5 * dYOffset << " ) "
                 << "( " << nNumBins << " , " << -1.5 * dYOffset << " ) " 
                 << endl;

            cout << "\\rput[t]( " << double (nNumBins) / 4.0 << " , " << -2.5 * dYOffset << " )"
                 << "{ $ \\scriptsize \\mu = " << setprecision(PRINT_PREC) << dMean << " $ }" 
                 << endl;
 
            cout << "\\rput[t]( " << 3.0 * double (nNumBins) / 4.0 << " , " << -2.5 * dYOffset << " )"
                 << "{ $ \\scriptsize \\sigma = " << setprecision(PRINT_PREC) <<  dStdDev << " $ }" 
                 << endl;
 
            cout << "\\end{pspicture}" << endl;
        }
    }

    return 0;
}



