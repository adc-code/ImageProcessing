////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_ComplexImage 
//
// Class used to manage and store a 'complex' image. 
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DIP_Defs.h"
#include "DIP_AbstractImage.h"
#include "DIP_ComplexImage.h"
#include "DIP_Math_Utils.h"

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


template class DIP_AbstractImage <DIP_COMPLEXPIXEL_TYPE>;



DIP_ComplexImage::DIP_ComplexImage ( unsigned int iWidth, unsigned int iHeight, DIP_IMAGE_TYPE iType ) 
                : DIP_AbstractImage <DIP_COMPLEXPIXEL_TYPE> ( iWidth, iHeight, iType )
{
}
 


DIP_ComplexImage::DIP_ComplexImage ( const DIP_ComplexImage & iImage )
                : DIP_AbstractImage <DIP_COMPLEXPIXEL_TYPE> ( iImage )
{
}



DIP_ComplexImage::~DIP_ComplexImage ()
{
}


 
bool DIP_ComplexImage::GetRealComponents ( DIP_RealImage *& oRealImage )
{
    bool bRetVal = false;

    if ( oRealImage )
        delete oRealImage;

    oRealImage = new DIP_RealImage ( _nWidth, _nHeight, _ImgType );
   
    if (oRealImage)
    {
        for (int i = 0; i < _ImgType; i++)
        {
            for (int j = 0; j < _nBufferSize; j++)
                oRealImage -> _PixelData [ i ][ j ] = _PixelData [ i ][ j ].real ();
        }

        bRetVal = true;
    }

    return bRetVal;
}



bool DIP_ComplexImage::GetImaginaryComponents ( DIP_RealImage *& oRealImage )
{
    bool bRetVal = false;

    if ( oRealImage )
        delete oRealImage;

    oRealImage = new DIP_RealImage ( _nWidth, _nHeight, _ImgType );
   
    if (oRealImage)
    {
        for (int i = 0; i < _ImgType; i++)
        {
            for (int j = 0; j < _nBufferSize; j++)
                oRealImage -> _PixelData [ i ][ j ] = _PixelData [ i ][ j ].imag ();
        }

        bRetVal = true;
    }

    return bRetVal;
}



bool DIP_ComplexImage::GetMagnitude ( DIP_RealImage *& oRealImage )
{
    bool bRetVal = false;

    if ( oRealImage )
        delete oRealImage;

    oRealImage = new DIP_RealImage ( _nWidth, _nHeight, _ImgType );
   
    if (oRealImage)
    {
        for (int i = 0; i < _ImgType; i++)
        {
            for (int j = 0; j < _nBufferSize; j++)
                oRealImage -> _PixelData [ i ][ j ] = std::abs (_PixelData [ i ][ j ] );
        }

        bRetVal = true;
    }

    return bRetVal;
}



bool DIP_ComplexImage::GetPhase ( DIP_RealImage *& oRealImage )
{
    bool bRetVal = false;

    if ( oRealImage )
        delete oRealImage;

    oRealImage = new DIP_RealImage ( _nWidth, _nHeight, _ImgType );
   
    if (oRealImage)
    {
        for (int i = 0; i < _ImgType; i++)
        {
            for (int j = 0; j < _nBufferSize; j++)
                oRealImage -> _PixelData [ i ][ j ] = atan2 ( _PixelData [ i ][ j ].imag (),
                                                              _PixelData [ i ][ j ].real () );
        }

        bRetVal = true;
    }

    return bRetVal;
}



bool DIP_ComplexImage::ComputeForwardFFT ( bool iShiftOrigin )
{
    bool bRetVal = false;

    if (iShiftOrigin)
        DoOriginShiftMult ();

    Compute2DFFT ( FFT_FORWARD );

    return bRetVal;
}



bool DIP_ComplexImage::ComputeInverseFFT ( bool iShiftOrigin )
{
    bool bRetVal = false;

    Compute2DFFT ( FFT_INVERSE );

    if (iShiftOrigin)
        DoOriginShiftMult ();

    return bRetVal;
}



void DIP_ComplexImage::ApplyFilterFunction  ( DIP_FREQFILTER_TYPE iType, 
                                              double              iCutoffLimit, 
                                              int                 iNValue )
{
    cout << "iCutoffLimit = " << iCutoffLimit << endl;
    // Since the image's dimensions can be different, the smaller of the two will be used
    // for the cut off distance.
    unsigned int nMaxRadius = _nWidth;
    if ( _nHeight > nMaxRadius )
        nMaxRadius = _nHeight;
    nMaxRadius /= 2;

    // Find the cut off distance... note that the square of the distance is kept so that
    // the square root does not need to be found each step to be slightly more efficient.     
    double dCutOffDistance = nMaxRadius * fabs (iCutoffLimit);
    dCutOffDistance *= dCutOffDistance;

    cout << "dCutOffDistance = " << nMaxRadius * fabs (iCutoffLimit) << endl;

    for (int j = 0; j < _nHeight; j++)
    {
        for (int i = 0; i < _nWidth; i++)
        {
            int nOffsetI = i - (_nWidth  / 2);
            int nOffsetJ = j - (_nHeight / 2);

            double dDistance = DIP_Math_Utils::ComputeDistance ( nOffsetI, nOffsetJ, false );

            //
            // Apply the various filters...
            //
            if ( iType == FREQ_IDEAL_LP || iType == FREQ_IDEAL_HP )
            {
                //
                // Ideal filter...
                //

                // have two regions... in and out of the filter.  The difference between the
                // low and high pass filters is what values are kept which is done by 
                // multiplying the values by one and zero.

                double dInFilterRegion  = 1.0;
                double dOutFilterRegion = 0.0;

                if ( iType == FREQ_IDEAL_HP )
                {
                    dInFilterRegion  = 0.0;
                    dOutFilterRegion = 1.0;
                }

                for (int c = 0; c < _ImgType; c++)
                {
                    int nPixelOffset = FindPixelOffset (i, j); 
                    if ( dDistance < dCutOffDistance )
                        _PixelData [ c ][ nPixelOffset ] = _PixelData [ c ][ nPixelOffset ] * dInFilterRegion;
                    else
                        _PixelData [ c ][ nPixelOffset ] = _PixelData [ c ][ nPixelOffset ] * dOutFilterRegion;
                }
            } 
            else if ( iType == FREQ_GAUSSIAN_LP || iType == FREQ_GAUSSIAN_HP )
            {
                //
                // Gaussian filter...
                //

                // Recall that the square of the distance values are kept
                double dFilterAmount = exp ( -1.0 * dDistance / (2.0 * dCutOffDistance) );

                if ( iType == FREQ_GAUSSIAN_HP )
                    dFilterAmount = 1.0 - dFilterAmount;

                for (int c = 0; c < _ImgType; c++)
                {
                    int nPixelOffset = FindPixelOffset (i, j); 
                    _PixelData [ c ][ nPixelOffset ] = _PixelData [ c ][ nPixelOffset ] * dFilterAmount;
                }

            }
            else if ( iType == FREQ_BUTTER_LP || iType == FREQ_BUTTER_HP )
            {
                //
                // Butterworth filter...
                //

                // Note that the formula is slightly different than the one in the book...
                // the two in the exponent is carried in so that the distances need to be 
                // squared (which is what we already have).
                double dFilterAmount = 1 / ( 1 + pow ( dDistance / dCutOffDistance, iNValue ) );

                if ( iType == FREQ_BUTTER_HP )
                    dFilterAmount = 1 - dFilterAmount;

                for (int c = 0; c < _ImgType; c++)
                {
                    int nPixelOffset = FindPixelOffset (i, j); 
                    _PixelData [ c ][ nPixelOffset ] = _PixelData [ c ][ nPixelOffset ] * dFilterAmount;
                }

            }
        }
    } 
}



void DIP_ComplexImage::DoOriginShiftMult ()
{
    for (int j = 0; j < _nHeight; j++)
    {
        for (int i = 0; i < _nWidth; i++)
        {
            for (int c = 0; c < _ImgType; c++)
            {
                if ( (i+j) % 2 == 1 )
                {
                    int nPixelOffset = FindPixelOffset (i, j);

                    _PixelData [ c ][ nPixelOffset ] = -1.0 * _PixelData [ c ][ nPixelOffset ];
                }
            }
        }
    }
}



void DIP_ComplexImage::Compute2DFFT ( bool iFFTDirection )
{
    vector <DIP_COMPLEXPIXEL_TYPE>  rowVector ( _nWidth  );
    vector <DIP_COMPLEXPIXEL_TYPE>  colVector ( _nHeight );

    int nLog2W = ( log (_nWidth)  / M_LN2 );
    int nLog2H = ( log (_nHeight) / M_LN2 );

    for (int c = 0; c < _ImgType; c++)
    {
        for (int j = 0; j < _nHeight; ++j)
        {
            for (int i = 0; i < _nWidth; ++i)
            {
                int revIndex = FFT_ReverseBits (i, _nWidth);

                DIP_COMPLEXPIXEL_TYPE zComplexNum;
                GetValue ( i, j, (DIP_IMAGE_CHANNEL)c, zComplexNum );
 
                rowVector [revIndex] = zComplexNum; 
            }

            Compute1DFFT (rowVector, _nWidth, nLog2W, iFFTDirection );

            for (int i = 0; i < _nWidth; ++i)
            {
                SetValue ( i, j, (DIP_IMAGE_CHANNEL)c, rowVector [i] );
            }
        }

        for (int i = 0; i < _nWidth; ++i)
        {
            for (int j = 0; j < _nHeight; ++j) 
            {
                int revIndex = FFT_ReverseBits (j, _nHeight);

                DIP_COMPLEXPIXEL_TYPE zComplexNum;
                GetValue ( i, j, (DIP_IMAGE_CHANNEL)c, zComplexNum );
 
                colVector [revIndex] = zComplexNum;
            }

            Compute1DFFT (colVector, _nHeight, nLog2H, iFFTDirection );

            for (int j = 0; j < _nHeight; ++j)
            {
                 SetValue ( i, j, (DIP_IMAGE_CHANNEL)c, colVector [j] );
            }
        } 
    }
}



int DIP_ComplexImage::FFT_ReverseBits (unsigned int index, int size)
{ 
    int rev = 0;
    for (; size > 1; size >>= 1)
    { 
        rev = (rev << 1) | (index & 1);
        index >>= 1;
    }

    return rev;
}



void DIP_ComplexImage::Compute1DFFT ( vector <DIP_COMPLEXPIXEL_TYPE> & complexData, 
                                      unsigned int iSize, 
                                      int iLog2n,
                                      bool iFFTDirection )
{
    double dAngle, wtmp, wpr, wpi, wr, wi;
    int n = 1, n2;
    double pi2 = M_PI * 2.0;
    double scale = 1.0 / iSize;

    DIP_COMPLEXPIXEL_TYPE zComplexNum;
    for (int k = 0; k < iLog2n; ++k)
    {
        n2 = n;
        n <<= 1;
        dAngle = (iFFTDirection) ? pi2/n : -pi2/n;
        wtmp = sin (0.5 * dAngle);

        wpr = -2.0 * wtmp*wtmp;
        wpi = sin (dAngle);
        wr = 1.0;
        wi = 0.0;

        for (int m = 0; m < n2; ++m) 
        {
            for (unsigned int i = m; i < iSize; i += n) 
            {
                int j = i+n2;
                DIP_COMPLEXPIXEL_TYPE zComplexNum ( 
                                 wr * complexData [j].real() - wi * complexData [j].imag(), 
                                 wr * complexData [j].imag() + wi * complexData [j].real() );

                complexData [j] = complexData [i] - zComplexNum;
                complexData [i] += zComplexNum;
            }

            wr = (wtmp=wr)*wpr - wi*wpi + wr;
            wi = wi*wpr + wtmp*wpi + wi;
        }
    }

    if (iFFTDirection)
    {
        for (int i = 0; i < n; i++)
        {
            complexData [i] *= scale;
        }
    }
}


/*
Complex* DIP_Math_Utils::fft1(Complex *data, unsigned int size, int log2n,  bool inverse)
{       
        double angle, wtmp, wpr, wpi, wr, wi;
        int n = 1, n2;
        double pi2 = M_PI * 2.0;
        double scale = 1.0/size;
        Complex tc;  
        for (int k = 0; k < log2n; ++k)
        {   
            n2 = n;
            n <<= 1;
            angle = (inverse)?pi2/n:-pi2/n;
            wtmp=sin(0.5*angle);
            wpr = -2.0*wtmp*wtmp;
            wpi = sin(angle);
            wr = 1.0;
            wi = 0.0;
            
            for (int m=0; m < n2; ++m) { 
                for (unsigned int i=m; i < size; i+=n) {
                    int j = i+n2;
                    //tc.real = wr * data[j].real() - wi * data[j].imag();
                    //tc.imag = wr * data[j].imag() + wi * data[j].real();
                    tc = Complex ( wr * data[j].real() - wi * data[j].imag(), wr * data[j].imag() + wi * data[j].real());
                    data[j] = data[i] - tc;
                    data[i] += tc;
                }
                wr=(wtmp=wr)*wpr-wi*wpi+wr;
                wi=wi*wpr+wtmp*wpi+wi;
            }
        }

        if(inverse) {
            for(int i = 0;i < n;i++) {
                data[i] *= scale;
            }
        }
        return data;
}
*/



/*
Complex** DIP_Math_Utils::fft2 (Complex **data, int r, int c, bool inverse)
{
    //cout << "### fft2 " << endl;
    Complex *row    = new Complex [r];
    Complex *column = new Complex [c];
    //int log2w = r >> 1;
    //int log2h = c >> 1;
    int log2w = (log(r) / log(2));
    int log2h = (log(c) / log(2));

    // Perform FFT on each row
    //cout << "  -> Perform FFT on each row " << endl;
    for (int y = 0; y < c; ++y)
    {
      for (int x = 0; x < r; ++x)
      {
        int rb = rev_bits (x, r);
        row[rb] = data[x][y];
      }
      row = fft1(row, r, log2w, inverse);
      for (int x = 0; x < r; ++x) {
        data[x][y] = row[x];
      }
    }

    // Perform FFT on each column
    //cout << "  ->  Perform FFT on each column " << endl;

    for (int x = 0;x < r; ++x) {
      for (int y = 0; y < c; ++y) {
            int rb = rev_bits(y, c);
            column[rb] = data[x][y];
      }
      column = fft1(column, c, log2h, inverse);
      for (int y = 0; y < c; ++y) {
        data[x][y] = column[y];
      }
    }
    return data;
} */
