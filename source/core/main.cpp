/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file main.cpp
 */


#include <cstdlib> // EXIT_SUCCESS

#include "keno_common.h"

int main( int argc, char *argv[] )
{
    if (argc < 2) {
        std::cout << "\n\n>>> ERROR. Please give a file as an argument.\n";
        return 1;
    }
    std::string fileAddress;
    std::stringstream (argv[1]) >> fileAddress;
    std::ifstream ifs_bet_file("../../data/" + fileAddress);

    if(!ifs_bet_file.is_open()) 
    {
        std::ostringstream oss;
        oss << "\n\n>>> Sorry, could not open bet file [" << fileAddress <<"].\n    Exiting...\n\n";
        std::cout << oss.str();
        return 1;
    }

    std::string dataLine( "" );

    std::getline (ifs_bet_file, dataLine);

    while(not ifs_bet_file.eof())
    {
        auto inputOk{ false };

        if(not inputOk)
        {
            
        }
    }


    return EXIT_SUCCESS;
}
