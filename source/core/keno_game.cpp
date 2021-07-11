/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file keno_game.cpp
 *
 */

#include "keno_game.h"

namespace Keno {

/// Prints out the welcoming message.
void KenoGame::welcome_message(void)
{
    std::cout << "===================================================\n";
    std::cout << "Welcome to the Keno game. Version 1.0. Developed by GT group.\n";
    std::cout << "---------------------------------------------------\n\n";
    std::cout << " We'll be processing your bet.\n\n";
    std::cout << "Good luck!\n";
    std::cout << "----------------------------------------------------\n";
}

//! Runs the game.
void KenoGame::run_game(void)
{
    std::cout << "You are going to wage a total of $" << m_credit << ". \n";
    std::cout << "Going for a total of" << m_NR << "rounds, waging $" << m_credit/m_NR << "per round. \n\n";
    std::cout << "Your bet has" << m_spots.size() << "numbers. They are: [ ";
    for(auto i:m_spots) std::cout << i << " ";
    std::cout << "]\n";
    std::cout << "  _______.________ \n";
    std::cout << "   Hits  | Payout  \n";
    std::cout << "  _______|________ \n";
    for(int i = 0; i <= m_spots.size(); i++){
        std::cout << "   " << i << "\t" << " | " << payout_table[m_spots.size()][i] << "\n";
    }
    std::cout << "Please, hit enter for the next round.";
    getchar();
}


} // namespace Keno


//============[ End KenoGame class ]===============//