/*

Very thin C++ wrapper for LAME library.
Enables easy PCM to MP3 conversion and vice versa.

Copyright (C) 2015 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 1589 $ $Date:: 2015-03-18 #$ $Author: serge $

#ifndef LIB_LAMEPLUS_H
#define LIB_LAMEPLUS_H

#include <lame/lame.h>

#include "namespace_lib.h"

NAMESPACE_LAMEPLUS_START

class LamePlus
{
public:
    LamePlus();
    ~LamePlus();

    int set_in_samplerate( int sample_rate );
    int set_brate( int byte_rate );

    int set_num_channels( int channels );
    int set_mode( MPEG_mode_e mode );

    int set_VBR( vbr_mode_e mode );
    int init_params();
    int encode_flush( unsigned char * mp3buf, int size );
    int encode_buffer(
            const short int     buffer_l [],   /* PCM data for left channel     */
            const short int     buffer_r [],   /* PCM data for right channel    */
            const int           nsamples,      /* number of samples per channel */
            unsigned char*      mp3buf,        /* pointer to encoded MP3 stream */
            const int           mp3buf_size ); /* number of valid octets in this
                                                  stream                        */

    int encode_buffer_interleaved(
            short int           pcm[],         /* PCM data for left and right
                                                  channel, interleaved          */
            int                 num_samples,   /* number of samples per channel,
                                                  _not_ number of samples in
                                                  pcm[]                         */
            unsigned char*      mp3buf,        /* pointer to encoded MP3 stream */
            int                 mp3buf_size ); /* number of valid octets in this
                                                  stream                        */
private:
    lame_t  lame_;
};

NAMESPACE_LAMEPLUS_END

#endif // LIB_LAMEPLUS_H
