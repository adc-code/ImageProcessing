////////////////////////////////////////////////////////////////////////////////////////////////////
//
// main.cpp
//
// Used to start the "DIP_ImageViewer" application
//
////////////////////////////////////////////////////////////////////////////////////////////////////


#include <QApplication>

#include "DIP_ImageViewer.h"


int main (int argc, char * argv [])
{
    //
    // Make an application instance
    //
    QApplication app (argc, argv);

    // 
    // Make a DIP_ImageView instance
    //
    DIP_ImageViewer  imageViewer;
    imageViewer.show ();

    //
    // Start the application
    //
    return app.exec ();
}


