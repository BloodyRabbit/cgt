/**
 * @file curses/NoteList.cpp
 *
 * Console Guitar Tuner (CGT)
 * Copyright (c) 2011 by Bloody.Rabbit
 *
 * @author Bloody.Rabbit
 */

#include "cgt-curses.h"

#include "curses/NoteList.h"

using namespace cgt;
using namespace cgt::curses;

/*************************************************************************/
/* cgt::curses::NoteList                                                 */
/*************************************************************************/
NoteList::NoteList( int xpos, int ypos, int width, int height )
: Window( xpos, ypos, width, height )
{
    // Init our color pair
    ::init_pair( PAIR_FUNDAMENTAL, COLOR_RED, -1 );
}

void NoteList::print( const util::Tone& tone, unsigned int harm )
{
    // Generate the name
    char name[ 0x20 ];
    tone.getName( name, sizeof( name ) );

    unsigned int off  = ::log2( harm + 1 ) + 1;

    if( 0 == harm )
        // Fundamental, turn on color
        attrOn( COLOR_PAIR( PAIR_FUNDAMENTAL ) );

    // Print it
    printw( " [%-*u] ", off, harm );

    attrOn( A_BOLD );
    printw( "%10s ", name );
    attrOff( A_BOLD );

#ifndef CGT_DEBUG_ANALYSIS_FREQ
    printw( "(%10.4f Hz)\n", tone.frequency() );
#else /* !CGT_DEBUG_ANALYSIS_FREQ */
    printw( "(%10.4f Hz) = ", tone.frequency() );

    attrOn( A_BOLD );
    printw( "%10.4f dB\n", 10 * ::log10( ::fabs( tone.frequency() - CGT_DEBUG_ANALYSIS_FREQ ) ) );
    attrOff( A_BOLD );
#endif /* !CGT_DEBUG_ANALYSIS_FREQ */

    if( 0 == harm )
        // Fundamental, turn off color
        attrOff( COLOR_PAIR( PAIR_FUNDAMENTAL ) );
}

void NoteList::refresh()
{
    // Draw a box
    box();

    // Refresh content of the window
    Window::noutRefresh();
    // Clear the window
    Window::erase();

    // Move cursor to the default position (remember our border)
    move( 1, 0 );
}
