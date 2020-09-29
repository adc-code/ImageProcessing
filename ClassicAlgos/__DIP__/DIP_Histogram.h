////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Histogram
//
// Class used to manage histograms and compute related items
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include <vector>
using namespace std;


#ifndef __DIP_HISTOGRAM_H__
#define __DIP_HISTOGRAM_H__



class DIP_Histogram
{
    public:

        //
        // Default constructor
        //   - Note that the number of bins needs to be specified
        //
        DIP_Histogram (unsigned int iNumBins);

        //
        // Copy Constructor
        //
        DIP_Histogram (const DIP_Histogram & iHistogram);

        //
        // Destructor
        //
       ~DIP_Histogram ();

        //
        // Overloaded assignment operator (used for copying)
        //
        DIP_Histogram &  operator= (const DIP_Histogram & iHistogram);


        //
        // Get the number of bins in the histogram
        //       
        unsigned int  GetNumberOfBins  ();


        // 
        // Data access related...
        //
        bool          GetValue         (unsigned int iBinNumber, double & oValue);
        bool          SetValue         (unsigned int iBinNumber, double   iValue);
        bool          IncrementValue   (unsigned int iBinNumber);
        
       
        //
        // Statistics related
        //
        double        ComputeMean      ();
        double        ComputeStdDev    ();

        bool          FindPeakValue    (unsigned int & oIndex, double & oValue);
        bool          FindMinValue     (unsigned int & oIndex);
        bool          FindMaxValue     (unsigned int & oIndex);
        unsigned int  FindTotalCount   ();

        bool          Normalize        ();
        bool          ComputeCDF       (vector <double> & oCDFValues);


    private:

        //
        // Default constructor...
        // note: is private so the specified constructor is called.
        //
        DIP_Histogram ();


        //
        // Data members
        //
        vector <double>  _dHistogramData;

};


#endif //__DIP_HISTOGRAM_H__



