/**
 * @file curses/TunerBar.h
 *
 * Console Guitar Tuner (CGT)
 * Copyright (c) 2011 by Bloody.Rabbit
 *
 * @author Bloody.Rabbit
 */

#ifndef __CGT__CURSES__TUNER_BAR_H__INCL__
#define __CGT__CURSES__TUNER_BAR_H__INCL__

#include "curses/Window.h"

namespace cgt { namespace curses {

/**
 * @brief A tuner bar.
 *
 * @author Bloody.Rabbit
 */
class TunerBar
: protected Window
{
public:
    /**
     * @brief Initializes the tuner bar.
     *
     * @param[in] xpos    Position in X-axis.
     * @param[in] ypos    Position in Y-axis.
     * @param[in] width   Size in X-axis.
     * @param[in] height  Size in Y-axis.
     */
    TunerBar( int xpos, int ypos, int width, int height );

    /**
     * @brief Add a fundamental tone.
     *
     * @param[in] tone The tone.
     */
    void add( const util::Tone& tone );
    /**
     * @brief Reprints the magnitude bar.
     */
    void refresh();

protected:
    /// Tuning tolerance.
    double mTuneTolerance;
};

}} // cgt::curses

#endif /* !__CGT__CURSES__TUNER_BAR_H__INCL__ */
