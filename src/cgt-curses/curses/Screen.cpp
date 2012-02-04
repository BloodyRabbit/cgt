/**
 * @file curses/Screen.cpp
 *
 * Console Guitar Tuner (CGT)
 * Copyright (c) 2011 by Bloody.Rabbit
 *
 * @author Bloody.Rabbit
 */

#include "cgt-curses.h"

#include "curses/Screen.h"

using namespace cgt::curses;

/*************************************************************************/
/* cgt::curses::Screen                                                   */
/*************************************************************************/
Screen::Screen( int xpos, int ypos, int width, int height )
  // Pull the value from the config manager
: mHarmonics( sConfigMgr[ "cgt.fft.harmonicTolerance" ] ),
  // Carefully positioned elements
  mConfig( xpos, ypos + height - 8 ),
  mNotes( xpos + ( width - 36 ) / 2, ypos + height / 2 )
{
    // Initial print of all windows
    mConfig.refresh();
    mNotes.refresh();
}

Screen::~Screen()
{
}

void Screen::start()
{
    // Flush harmonics.
    mHarmonics.clear();
    // Clear note list
    mNotes.clear();
}

void Screen::add( double freq, double )
{
    // Add the note to the list
    mNotes.print( freq, mHarmonics.get( freq ) );
}

void Screen::end()
{
    // Print the notes
    mNotes.refresh();
}
