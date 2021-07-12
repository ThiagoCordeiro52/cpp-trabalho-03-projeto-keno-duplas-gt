/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file main.cpp
 */


#include <cstdlib> // EXIT_SUCCESS

#include "keno_common.h"
#include "keno_bet.h"
#include "keno_game.h"
#include "enter.h"
#include <iterator>
#include <sstream>
 

int main( int argc, char *argv[] )
{
    std::string returnEnter;

    Keno::GameInput gi;
    returnEnter = validateEnter(argc, argv, gi);
    if(returnEnter == "1") 
    {
        return 1;
    }
    Keno::KenoGame game{gi}; // KenoGame constructor.
    game.welcome_message();
    game.run_game();

    return EXIT_SUCCESS;
}
