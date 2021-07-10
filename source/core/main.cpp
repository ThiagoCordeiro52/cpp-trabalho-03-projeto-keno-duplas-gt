/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file main.cpp
 */


#include <cstdlib> // EXIT_SUCCESS

#include "keno_common.h"
#include <iterator>
#include <sstream>
 

int main( int argc, char *argv[] )
{
    if (argc < 2) {
        std::cout << "\n\n>>> ERROR. Please give a file as an argument.\n";
        return 1;
    }

    std::string fileAddress;
    float credits;
    int rounds;
    std::vector<int> spots;
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
    auto inputOk{ false };
    while(not ifs_bet_file.eof() and not inputOk)
    {
        if(not inputOk)
        {
            if(std::stringstream (dataLine) >> credits) 
            {
                if (credits <= 0.f) {
                    std::ostringstream oss;
                    oss << "\n\n>>> ERROR: Invalid wage value [" << dataLine <<"], in your bet file ["<< fileAddress<<"]\n    Exiting...\n\n";
                    std::cout << oss.str();
                    return 1;
                }
                inputOk = true;
            }
        }
        std::getline (ifs_bet_file, dataLine);
    }

    inputOk = false;
    while(not ifs_bet_file.eof() and not inputOk)
    {

        if(not inputOk)
        {
            if(std::stringstream (dataLine) >> rounds) 
            {
                if (rounds <= 0) {
                    std::ostringstream oss;
                    oss << "\n\n>>> ERROR: Invalid number of rounds provided in your bet file ["<< fileAddress<<"]\n    Exiting...\n\n";
                    std::cout << oss.str();
                    return 1;
                }
                inputOk = true;
            }

        }
        std::getline (ifs_bet_file, dataLine);
    }

    inputOk = false;
    int value;

    while(not ifs_bet_file.eof() and not inputOk)
    {
        std::stringstream values ( dataLine );
        std::vector<std::string> valuesVectorString;
        valuesVectorString.clear();
        valuesVectorString.insert( valuesVectorString.begin(),
            std::istream_iterator<std::string >( values ),
            std::istream_iterator<std::string>( ) );
        for (auto i = valuesVectorString.begin(); i != valuesVectorString.end(); i++) 
        {
            value = std::stoi((*i));
            if(value > 0 && value <= 80) {
                spots.push_back(value);
            }
        }
        // std::cout <<  spots.size() << "\n"; // size
    
            
        if (spots.size() != 0)
        { 
            inputOk = true;
        } 
        else 
        {
            std::getline (ifs_bet_file, dataLine);
        }
    }
    
    Keno::GameInput gi;
    gi.IC = credits;
    gi.NR = rounds;
    std::copy(spots.begin(), spots.end(),
              std::back_inserter(gi.spots));
    // cout << spots.size() << " " << gi.spots.size();       

    return EXIT_SUCCESS;
}
