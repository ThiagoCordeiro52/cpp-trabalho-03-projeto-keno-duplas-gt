#ifndef _KENO_GAME_H_
#define _KENO_GAME_H_


/*!
 *  Class that defines a Keno game.
 *
 *  @author GT group
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
            //! Creates a Keno game.
            /*! The Keno game is the game manager.
             *  @param game_input Struct of GameInput type which contains Input Credit, Number of Rounds and Player's spots.
             */
            KenoGame(GameInput game_input){
                m_credit = game_input.IC;
                m_NR = game_input.NR;
                m_game_spots = game_input.spots;
            }

            //! Prints out the welcoming message.
            void welcome_message(void);

            //! Runs the game.
            void run_game(void);

        private:
            Keno::set_of_numbers_type m_game_spots; //<! The player's bet, i.e.\ a set of numbers (aka spots).
            Keno::set_of_numbers_type m_draw; //<! The set of numbers the game randomly generates; these numbers are unique, which means no repetition.
            Keno::cash_type m_credit;             //<! The player's credit.
            Keno::number_type m_NR;            //<! Number of rounds.
            float payout_table[15][16] = 
            {   {0, 3},                 // line 1
                {0, 1, 9},              // line 2
                {0, 1, 2, 16},          // line 3
                {0, 0.5, 2, 6, 12},     // line 4
                {0, 0.5, 1, 3, 15, 50}, // line 5
                {0, 0.5, 1, 2, 3, 30, 75}, // line 6
                {0, 0.5, 0.5, 1, 6, 12, 36, 100}, // line 7
                {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720}, // line 8
                {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200}, // line 9
                {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800}, // line 10
                {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000}, // line 11
                {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000}, // line 12
                {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000}, // line 13
                {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500}, // line 14
                {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000} // line 15
            };
        friend class KenoBet;
    };
}

#endif