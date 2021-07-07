/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file main.cpp
 */


#include <cstdlib> // EXIT_SUCCESS

#include "keno_common.h"

// int strToInt ( std::string inputStr_ ) {
// // Criando o fluxo ‘ iss ’ e associando - o a ‘ inputStr_ ’.
//     std::istringstream iss ( inputStr_ );
//     int value;
//     iss >> value >> std::ws ; // Ignora espaço em branco depois .
//     if ( iss.fail() or !iss.eof()) {
//         std::cerr << " strToInt (): Erro , illegal integer format .\n";
//     }
//     return value;
// }

int main( int argc, char *argv[] )
{
    if (argc < 2) {
        std::cout << "Please give a file as an argument.\n";
        return 1;
    }
    int counter {0};
    std::string val;
    std::string arquivo {"../../data/"};
    arquivo += argv[1];
    std::ifstream ifs (arquivo); // 2 em 1: Abre o " arquivo . txt " E associa ao fluxo ‘ ifs ’.
    while ( ifs >> val ) {
        std::cout << val << "\n";
        ++counter;
        if((counter == 1 || counter == 2) && val.empty())
        {
            std::cout << "ERROR";
            break;

        }
    }
    ifs.close();
    std::cout << "Total" << counter << "\n";


    return EXIT_SUCCESS;
}
