////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DIP_Image_FileUtils.h 
//
// Set of utility functions used to read and write simple image files.
//
////////////////////////////////////////////////////////////////////////////////////////////////////



#include "DIP_Image.h"

#include <fstream>
#include <string>
using namespace std;



#ifndef __DIP_IMAGE_FILEUTILS_H__
#define __DIP_IMAGE_FILEUTILS_H__


// 
// enumeration used to specify the supported file types.  Note currently only supporting netpbm
// image formats for simplicity.
// 
enum DIP_IMAGE_FILETYPE
{
    BAD_FILE,
    PGM_ASCII,
    PGM_BINARY
};


#define   PGM_ASCII_FILE    string ("P2")
#define   PGM_BINARY_FILE   string ("P5")
#define   PPM_ASCII_FILE    string ("P3")
#define   PPM_BINARY_FILE   string ("P6")


#define   READ_BUFFER_SIZE  100



class DIP_Image_FileUtils
{
    public:

        //
        // ReadPGMFile: used to read a PGM based image file
        //        
        static  bool  ReadPGMFile  (string iFilename, DIP_Image *& opImage);

        //
        // WritePGMFile: used to write a PGM base file...
        //
        static  bool  WritePGMFile (string oFilename, DIP_Image * ipImage, DIP_IMAGE_FILETYPE fileType);

        //
        // ReadPPMFile: used to read a PPM based image file
        //        
        static  bool  ReadPPMFile  (string iFilename, DIP_Image *& opImage);

        //
        // WritePPMFile: used to write a PPM base file...
        //
        static  bool  WritePPMFile (string oFilename, DIP_Image * ipImage, DIP_IMAGE_FILETYPE fileType);


    private:

        //
        // Reading/Input related... 
        //

        // Get the image type (binary or ascii)
        static  DIP_IMAGE_FILETYPE  ReadPGMFile_HeaderID         (ifstream & inputfile);

        // Get the image information... width, height, max value
        static  bool                ReadPGMFile_HeaderInfo       (ifstream & inputfile,
                                                                  unsigned int & oWidth,
                                                                  unsigned int & oHeight,
                                                                  unsigned int & oMaxColour);

        // Get all the pixel information using ascii mode
        static  bool                ReadPGMFile_ReadAsciiData    (ifstream & inputFile, DIP_Image * pImage);

        // Get all the pixel information using binary mode
        static  bool                ReadPGMFile_ReadBinaryData   (ifstream & inputFile, DIP_Image * pImage);

        

        //
        // Writing/Output related...
        //

        // Write out the image type (binary or ascii)
        static  bool                WritePGMFile_HeaderID        (ofstream & outputFile, DIP_IMAGE_FILETYPE iType);

        // write out the header info... width, height, max value
        static  bool                WritePGMFile_HeaderInfo      (ofstream & outputFile, DIP_Image * pImage);

        // write out all the pixel data using ascii mode
        static  bool                WritePGMFile_WriteAsciiData  (ofstream & outputFile, DIP_Image * pImage);

        // write out all the pixel data using binary mode
        static  bool                WritePGMFile_WriteBinaryData (ofstream & outputFile, DIP_Image * pImage);



        //
        // Other stuff...
        //

        // Determine the number of bits per pixel required.
        static unsigned int        CalcBitsPerPixel             (unsigned int iMaxColour);

};


#endif //__DIP_IMAGE_FILEUTILS_H__



