/*!
 *  This function implements the entry validation.
 *
 *  @author GT group
 *  @file enter.cpp
 *
 */

#include "keno_common.h"
#include "enter.h"
#include <iterator>
#include <sstream>
#include <iostream>

   std::string validateEnter (int argc, char * argv[], Keno::GameInput & gi) {
    if (argc < 2) {
        std::cout << "\n\n>>> ERROR. Please give a file as an argument.\n";
        return "1";
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
        return "1";
    }

    std::string dataLine( "" );

    std::getline (ifs_bet_file, dataLine);
    auto inputOk{ false };
    bool corrupted = true;
    while(not ifs_bet_file.eof() and not inputOk)
    {
        if(not inputOk)
        {
            if(std::stringstream (dataLine) >> credits) 
            {
                if (credits <= 0.f || credits > 100000) {
                    std::ostringstream oss;
                    oss << "\n\n>>> ERROR: Invalid wage value [" << std::stoi(dataLine) <<"], in your bet file ["<< fileAddress<<"]\n    Exiting...\n\n";
                    std::cout << oss.str();
                    return "1";
                }
                inputOk = true;
                corrupted = false;
            }
        }
        std::getline (ifs_bet_file, dataLine);
    }

    if(corrupted) {
        std::ostringstream oss;
        oss << "\n\n>>> ERROR: Invalid wage value, in your bet file ["<< fileAddress<<"]\n    Exiting...\n\n";
        std::cout << oss.str();
        return "1";
    }

    corrupted = true;

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
                    return "1";
                }
                inputOk = true;
                corrupted = false;
            }

        }
        std::getline (ifs_bet_file, dataLine);
    }

    if(corrupted) {
        std::ostringstream oss;
        oss << "\n\n>>> ERROR: Invalid number of rounds provided in your bet file ["<< fileAddress<<"]\n    Exiting...\n\n";
        std::cout << oss.str();
        return "1";      
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
        std::sort(spots.begin(), spots.end()); // Sort spots.
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

    gi.IC = credits;
    gi.NR = rounds;
    std::copy(spots.begin(), spots.end(),
              std::back_inserter(gi.spots));
    return "0";
  }
  