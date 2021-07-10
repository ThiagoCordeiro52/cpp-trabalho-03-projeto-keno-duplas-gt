#ifndef _KENO_GAME_H_
#define _KENO_GAME_H_


/*!
 *  Class that defines a Keno game.
 *
 *  @author
 *  @file keno_game.h
 */

#include "keno_common.h"

namespace Keno
{
    // struct GameInput{
    //     Keno::cash_type IC;
    //     int NR;
    //     Keno::set_of_numbers_type m_spots;
    // };

    class KenoGame
    {
        public:
            //! Prints out the welcoming message.
            void welcome_message(void);

        private:
            Keno::set_of_numbers_type m_spots; //<! The player's bet, i.e.\ a set of numbers (aka spots).
            Keno::cash_type m_wage;             //<! The player's wage
    };
}

#endif