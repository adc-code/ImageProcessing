////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_ImageFileUtils
//
// Set of utility functions used to read and write simple image files.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Defs.h"
#include "DIP_Image.h"
#include "DIP_Image_FileUtils.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ReadPGMFile : attempts to read a PGM file
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::ReadPGMFile (string iFilename, DIP_Image *& opImage)
{
    bool bState = false;

    ifstream inputFile (iFilename.c_str());
    if (inputFile.is_open ())
    {
        DIP_IMAGE_FILETYPE fileType = ReadPGMFile_HeaderID (inputFile);

        unsigned int nWidth;
        unsigned int nHeight;
        unsigned int nMaxColour;

        bState = ReadPGMFile_HeaderInfo (inputFile, nWidth, nHeight, nMaxColour);

        if (opImage)
            delete opImage;

        opImage = new DIP_Image ( nWidth, nHeight, GREY,
                                  (DIP_IMAGE_BPP) CalcBitsPerPixel (nMaxColour) );

        // Make a new image and populate it with the data from the file
        if (fileType == PGM_ASCII)
        {
            bState = ReadPGMFile_ReadAsciiData (inputFile, opImage);
        }
        else if (fileType == PGM_BINARY)
        {
            // close inputfile and reopen it in binary mode
            long currentPos = inputFile.tellg ();
            inputFile.close ();
            inputFile.open (iFilename.c_str(), ios_base::binary | ios::in);
            inputFile.seekg (currentPos, ios::beg);

            bState = ReadPGMFile_ReadBinaryData (inputFile, opImage);
        }

        inputFile.close ();
    }    

    return bState; 
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ReadPGMFile_HeaderID
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
DIP_IMAGE_FILETYPE DIP_Image_FileUtils::ReadPGMFile_HeaderID (ifstream & inputFile)
{
    DIP_IMAGE_FILETYPE fileType = BAD_FILE;

    if (inputFile.is_open ())
    {
        //
        // Note that this perhaps is not the best way to do this, but we are trying to
        // focus on image processing not parsing of data
        //

        char inputBuffer [READ_BUFFER_SIZE];
        inputFile.getline (inputBuffer, READ_BUFFER_SIZE);

        string sToken (inputBuffer);
        if (sToken.compare (PGM_ASCII_FILE) == 0)
            fileType = PGM_ASCII;
        else if (sToken.compare (PGM_BINARY_FILE) == 0)
            fileType = PGM_BINARY;
    }

    return fileType;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ReadPGMFile_HeaderInfo
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::ReadPGMFile_HeaderInfo (ifstream & inputFile, 
                                                  unsigned int & oWidth,
                                                  unsigned int & oHeight,
                                                  unsigned int & oMaxColour)
{
    bool bOk = false;

    if (inputFile.is_open ())
    {
        char    c;
        bool    bSkip = false;
        int     nNumValues = 0;
        string  sTempNum ("");
        int     nNumDigits = 0;

        while (nNumValues < 3 && inputFile.eof () == false)
        {
            inputFile.get (c);

            if (c == '#')
            {
                // is comment... can skip the rest of the line
                bSkip = true;
            }
            else if (bSkip)
            {
                if (c == 10 || c == 13)
                    bSkip = false;
            }
            else if (isdigit (c))
            {
                sTempNum += c;
            }
            else if (c == 32 || c == 9 || c == 10 || c == 13)
            {
                if (nNumDigits == 0)
                {
                    oWidth = (unsigned int) stoi (sTempNum);
                    nNumDigits ++;
                    sTempNum = "";
                }
                else if (nNumDigits == 1)
                {
                    oHeight = (unsigned int) stoi (sTempNum);
                    nNumDigits ++;
                    sTempNum = "";
                }
                else if (nNumDigits == 2)
                { 
                    oMaxColour = (unsigned int) stoi (sTempNum);
                    nNumDigits ++;
                    sTempNum = "";
                    break;
                }
            }
        } // while

        if (nNumValues == 3)
            bOk = true;
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ReadPGMFile_ReadAsciiData
//
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::ReadPGMFile_ReadAsciiData (ifstream & inputFile, DIP_Image * pImage)
{
    bool bState = false;

    if (inputFile.is_open () && pImage)
    {
        string       sToken;
        int          nTokensRead     = 0;
        int          nTokensExpected = pImage -> GetWidth () * pImage -> GetHeight ();
        unsigned int nImgWidth       = pImage -> GetWidth ();

        int          nPixelCol = 0;
        int          nPixelRow = 0;

        while (inputFile.eof () == false && nTokensRead <= nTokensExpected)
        {
            inputFile >> sToken;

            unsigned int nValue = stoi (sToken);

            pImage -> SetPixel (nPixelCol, nPixelRow, nValue);

            nPixelCol ++;

            if (nPixelCol == nImgWidth)
            {
                nPixelCol = 0;
                nPixelRow ++;
            }
            
            nTokensRead ++;
        }
    }

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// ReadPGMFile_ReadBinaryData
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::ReadPGMFile_ReadBinaryData (ifstream & inputFile, DIP_Image * pImage)
{
    bool bState = false;

    if (inputFile.is_open () && pImage)
    {
        char         buffer;
        int          nBytesRead      = 0;
        int          nBytesExpected  = pImage -> GetWidth () * pImage -> GetHeight ();
        unsigned int nImgWidth       = pImage -> GetWidth ();

        int          nPixelCol = 0;
        int          nPixelRow = 0;

        while (inputFile.eof () == false && nBytesRead <= nBytesExpected)
        {
            inputFile.read (&buffer, 1);

            unsigned char uc = (unsigned char) buffer;
            unsigned int nValue = (unsigned int) uc;

            pImage -> SetPixel (nPixelCol, nPixelRow, nValue);

            nPixelCol ++;

            if (nPixelCol == nImgWidth)
            {
                nPixelCol = 0;
                nPixelRow ++;
            }
            
            nBytesRead ++;
        } 

        bState = true;
    }    

    return bState;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// WritePGMFile
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::WritePGMFile (string oFilename, DIP_Image * ipImage, 
                                        DIP_IMAGE_FILETYPE fileType) 
{
    bool bOk = false;

    if (ipImage)
    {
        ofstream outputFile (oFilename.c_str());

        if (outputFile.is_open ())
        {
            WritePGMFile_HeaderID (outputFile, fileType);

            WritePGMFile_HeaderInfo (outputFile, ipImage);     

            if (fileType == PGM_ASCII)
            {
                WritePGMFile_WriteAsciiData (outputFile, ipImage);
            }
            else if (fileType == PGM_BINARY)
            {
                // close the file and reopen it as binary.
                outputFile.close ();
                outputFile.open (oFilename.c_str(), ios_base::binary | ios::out | ios::app);

                WritePGMFile_WriteBinaryData (outputFile, ipImage); 
            }

            outputFile.close ();
        }
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// WritePGMFile_HeaderID
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::WritePGMFile_HeaderID (ofstream & outputFile, DIP_IMAGE_FILETYPE iType)
{
    bool bOk = false;

    if (outputFile.is_open ())
    {
        if (iType == PGM_ASCII)
        {
            outputFile << PGM_ASCII_FILE << endl;   
            bOk = true;
        }
        else if (iType == PGM_BINARY)
        {
            outputFile << PGM_BINARY_FILE << endl;
            bOk = true;
        }
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// WritePGMFile_HeaderInfo
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::WritePGMFile_HeaderInfo (ofstream & outputFile, DIP_Image * pImage)
{
    bool bOk = false;

    if (outputFile.is_open () && pImage)
    {
        outputFile << pImage -> GetWidth () 
                   << " "
                   << pImage -> GetHeight ()
                   << endl;

        outputFile << pImage -> GetMaxPixelValue ()
                   << endl;

        bOk = true;
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// WritePGMFile_WriteAsciiData
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::WritePGMFile_WriteAsciiData (ofstream & outputFile, DIP_Image * pImage)
{
    bool bOk = false;

    if (outputFile.is_open () && pImage)
    {
        unsigned int nWidth  = pImage -> GetWidth ();
        unsigned int nHeight = pImage -> GetHeight ();

        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                int nPixelValue = 0;
                if (pImage -> GetPixel (i, j, nPixelValue))
                {
                    outputFile << (unsigned int) nPixelValue << " ";
                }
            }

            outputFile << endl;
        }

        bOk = true;
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// WritePGMFile_WriteBinaryData
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DIP_Image_FileUtils::WritePGMFile_WriteBinaryData (ofstream & outputFile, DIP_Image * pImage)
{
    bool bOk = false;

    if (outputFile.is_open () && pImage)
    {
        unsigned int nWidth  = pImage -> GetWidth ();
        unsigned int nHeight = pImage -> GetHeight ();

        for (int j = 0; j < nHeight; j++)
        {
            for (int i = 0; i < nWidth; i++)
            {
                int nPixelValue = 0;
                if (pImage -> GetPixel (i, j, nPixelValue))
                {
                    char c = (char) nPixelValue;
                    outputFile.write (&c, sizeof (char));
                }
            }
        }

        bOk = true;
    }

    return bOk;
}



////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// CalcBitsPerPixel
// 
////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DIP_Image_FileUtils::CalcBitsPerPixel (unsigned int iMaxColour)
{
    return ceil (log ( iMaxColour + 1 ) / M_LN2);
}


