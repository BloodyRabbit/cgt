/**
 * @file cgt-curses.cpp
 *
 * Console Guitar Tuner (CGT)
 * Copyright (c) 2011 by Bloody.Rabbit
 *
 * @author Bloody.Rabbit
 */

#include "cgt-curses.h"

#include "curses/LibInit.h"
#include "curses/Observer.h"

void loadDefaultCfg()
{
    sConfigMgr[ "cgt-curses.pcmDevice"   ] = "plug:hdmi_linein";
    sConfigMgr[ "cgt-curses.pcmRate"     ] = 48000;
    sConfigMgr[ "cgt-curses.bufferSize"  ] = 4096;
    sConfigMgr[ "cgt-curses.captureSize" ] = 1024;

    sConfigMgr[ "cgt-curses.fft.magnitudeCutoff" ] = 7.5;
}

int main( int argc, char* argv[] )
{
    // Setup configuration
    loadDefaultCfg();

    // Load config
    config::ArgvParser argvParser;
    int code = argvParser.parse( argc, argv );
    if( 0 > code )
        return EXIT_FAILURE;

    // Shift arg vector
    argc -= code;
    argv += code;

    // Init curses screen
    curses::LibInit curs;
    curs.cBreak();
    curs.noEcho();
    curs.setCursor( 0 );
    curs.setTimeout( 0 );

    // Allocate the necessary classes
    curses::Observer  obs;
    core::FftAnalyser analyser( obs, sConfigMgr[ "cgt-curses.fft.magnitudeCutoff" ] );

    // Initialize the process
    if( !analyser.init( sConfigMgr[ "cgt-curses.pcmDevice" ],
                        sConfigMgr[ "cgt-curses.pcmRate" ],
                        sConfigMgr[ "cgt-curses.bufferSize" ],
                        sConfigMgr[ "cgt-curses.captureSize" ] ) )
    {
        ::puts( "Failed to initialize PCM" );
        return EXIT_FAILURE;
    }

    // Main loop
    while( 'q' != ::getch() )
    {
        // Run the step
        if( !analyser.step() )
        {
            ::puts( "An error occurred during processing" );
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}