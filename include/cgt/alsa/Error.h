/**
 * @file alsa/Error.h
 *
 * Console Guitar Tuner (CGT)
 * Copyright (c) 2011 by Bloody.Rabbit
 *
 * @author Bloody.Rabbit
 */

#ifndef __ALSA__ERROR_H__INCL__
#define __ALSA__ERROR_H__INCL__

/**
 * @brief Contains ALSA interface utilities.
 *
 * @author Bloody.Rabbit
 */
namespace alsa {

/**
 * @brief An ALSA error.
 *
 * @author Bloody.Rabbit
 */
class Error
{
public:
    /**
     * @brief The primary constructor.
     *
     * @param[in] code The error code.
     */
    Error( int code = 0 ) : mCode( code ) {}

    /**
     * @brief Obtains the ALSA error code.
     *
     * @return The numerical error code.
     */
    int code() const { return mCode; }
    /**
     * @brief Obtains an ALSA error description.
     *
     * @return A textual error description.
     */
    const char* what() const { return ::snd_strerror( code() ); }

    /**
     * @brief Determines if an error occurred.
     *
     * @retval true  An error occurred.
     * @retval false No error occurred.
     */
    operator bool() const { return 0 > code(); }

protected:
    /// The ALSA error code.
    int mCode;
};

} // namespace alsa

#endif /* !__ALSA__ERROR_H__INCL__ */
