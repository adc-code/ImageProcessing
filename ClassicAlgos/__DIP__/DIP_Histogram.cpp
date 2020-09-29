////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Histogram
//
// Class used to manage histograms and compute related items
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "DIP_Histogram.h"

#include <cmath>


//
// Constructor... DIP_Histogram
// 
DIP_Histogram::DIP_Histogram (unsigned int iNumBins)
{
    if (iNumBins > 0)
    {
        _dHistogramData.resize (iNumBins, 0);
    }
}



//
// Copy Constructor... 
// 
DIP_Histogram::DIP_Histogram (const DIP_Histogram & iHistogram)
{
    _dHistogramData = iHistogram._dHistogramData;
}



//
// Destructor... 
// 
DIP_Histogram::~DIP_Histogram ()
{
    _dHistogramData.clear ();
}



//
// Assignment operator
// 
DIP_Histogram &  DIP_Histogram::operator= (const DIP_Histogram & iHistogram)
{
    _dHistogramData = iHistogram._dHistogramData;

    return *this;
}



// 
// GetNumberOfBins
//
unsigned int DIP_Histogram::GetNumberOfBins ()
{
    return _dHistogramData.size ();
}



//
// GetValue
//
bool DIP_Histogram::GetValue (unsigned int iBinNumber, double & oValue)
{
    bool bRetVal = false;

    if (iBinNumber < _dHistogramData.size ())
    {
        oValue  = _dHistogramData [ iBinNumber ];

        bRetVal = true;
    }

    return bRetVal;   
}



//
// SetValue
//
bool DIP_Histogram::SetValue (unsigned int iBinNumber, double iValue)
{
    bool bRetVal = false;

    if (iBinNumber < _dHistogramData.size ())
    {
        _dHistogramData [ iBinNumber ] = iValue;

        bRetVal = true;
    }

    return bRetVal;   
}



//
// IncrementValue
//
bool DIP_Histogram::IncrementValue (unsigned int iBinNumber)
{
    bool bRetVal = false;

    if (iBinNumber < _dHistogramData.size ())
    {
        _dHistogramData [ iBinNumber ] ++;

        bRetVal = true;
    }

    return bRetVal;   
}

        
       
//
// ComputeMean 
//
double DIP_Histogram::ComputeMean ()
{
    double dRetVal = -1;

    int nNumBins = _dHistogramData.size ();
    if (nNumBins > 0)
    {
        double dCount = 0;
        double dTotal = 0;
        for (int i = 0; i < nNumBins; i++)
        {
            dCount += i * _dHistogramData [ i ];
            dTotal +=     _dHistogramData [ i ];
        }

        dRetVal = dCount / dTotal;
    }

    return dRetVal;   
}



//
// ComputeStdDev
//
double DIP_Histogram::ComputeStdDev ()
{
    double dRetVal = -1;

    // Perhaps not the most efficient... 
    double dMean = ComputeMean ();
  
    int nNumBins = _dHistogramData.size ();
    if (nNumBins > 0)
    {
        double dTotal      = 0;
        double dTotalVar   = 0;
        double dDifference = 0;

        for (int i = 0; i < nNumBins; i++)
        {
            dDifference =  (i  - dMean);
            dTotalVar   += _dHistogramData [ i ] * (dDifference * dDifference);
            dTotal      += _dHistogramData [ i ];
        }

        dRetVal = sqrt ( dTotalVar / dTotal );
    }

    return dRetVal;   
}



//
// FindPeakValue
//
bool DIP_Histogram::FindPeakValue (unsigned int & oIndex, double & oValue)
{
    bool bRetVal = false;
   
    int nNumBins = _dHistogramData.size ();
    if (nNumBins > 0)
    {
        double dMaxValue = -1;
        double dMaxIndex = -1;

        for (int i = 0; i < nNumBins; i++)
        {
            if ( _dHistogramData [ i ] > dMaxValue )
            {
                dMaxValue = _dHistogramData [ i ];
                dMaxIndex = i;
            }
        }

        if (dMaxValue > 0)
        {
            oIndex  = dMaxIndex;
            oValue  = dMaxValue;

            bRetVal = true;
        }
    }
    
    return bRetVal; 
}



//
// Normalize
// 
bool DIP_Histogram::Normalize ()
{
    bool bRetVal = false;

    unsigned int nMaxIndex = -1;
    double dMaxValue = -1;

    if ( FindPeakValue (nMaxIndex, dMaxValue) )
    {
        int nNumBins = _dHistogramData.size ();
        for (int i = 0; i < nNumBins; i++)
        {
            _dHistogramData [ i ] /= dMaxValue;
        }
    }

    return bRetVal;
}



//
// FindTotalCount
//
unsigned int DIP_Histogram::FindTotalCount ()
{
    unsigned int nTotalCount = 0;

    int nNumBins = _dHistogramData.size ();
    for (int i = 0; i < nNumBins; i++)
    {
        nTotalCount += _dHistogramData [i];
    }
  
    return nTotalCount;
}



//
// ComputeCDF
//
bool DIP_Histogram::ComputeCDF (vector <double> & oCDFValues)
{
    bool bRetVal = false;

    int nNumBins = _dHistogramData.size ();
    if (nNumBins > 0)
    {
        oCDFValues = _dHistogramData;
        for (int i = 1; i < nNumBins; i++)
        {
            oCDFValues [i] += oCDFValues [i-1];
        }

        unsigned int nTotalCount = FindTotalCount ();
        for (int i = 0; i < nNumBins; i++)
        {
            oCDFValues [i] /= nTotalCount;
        }        

        bRetVal = true;
    }

    return bRetVal;
}



