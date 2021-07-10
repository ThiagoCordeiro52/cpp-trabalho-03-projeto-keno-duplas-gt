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


} // namespace Keno


//============[ End KenoGame class ]===============//