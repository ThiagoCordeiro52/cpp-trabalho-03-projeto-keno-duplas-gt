/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file keno_game.cpp
 *
 */

#include "keno_game.h"
#include "keno_bet.h"

namespace Keno {

/// Prints out the welcoming message.
void KenoGame::welcome_message(void)
{
    std::cout << "===================================================\n";
    std::cout << "Welcome to the Keno game. Version 1.0. Developed by GT group.\n";
    std::cout << "---------------------------------------------------\n\n";
    std::cout << "We'll be processing your bet.\n\n";
    std::cout << "Good luck!\n";
    std::cout << "----------------------------------------------------\n";
}

//! Runs the game.
void KenoGame::run_game(void)
{
    KenoBet bet;
    for (auto i = m_game_spots.begin(); i != m_game_spots.end(); ++i) {
        bet.add_spot(*i);
    }
    bet.set_wage(m_credit/m_NR);
    // m_game_spots.clear();
    // m_game_spots = bet.get_spots();
    // COLOCAR IF PRO WAGE: talvez

    std::cout << "You are going to wage a total of $" << m_credit << ". \n";    // Prints total credits.
    std::cout << "Going for a total of " << m_NR << " rounds, waging $" << bet.get_wage() << " per round. \n\n"; // Prints number of rounds and wage per round.

    /* Prints player's bet. */
    std::cout << "Your bet has " << bet.size() << " numbers. They are: [ ";
    for(auto i:bet.get_spots()) std::cout << i << " ";      //Prints player's bet.
    std::cout << "]\n";

    /* Payout Table */
    std::cout << "  _______.________ \n";
    std::cout << "   Hits  | Payout  \n";
    std::cout << "  _______|________ \n";
    for(int i = 0; i <= (int) bet.size(); i++){
        std::cout << "   " << i << "\t" << " | " << payout_table[m_game_spots.size()][i] << "\n";
    }
    std::cout << "\n";

    // std::cout << "Please, hit enter for the next round.";
    // getchar();


    Keno::set_of_numbers_type v;  // Declares a vector v to store numbers from 1 to 80.
    for(int i = 1; i <= 80; i++){ // Stores numbers 1 to 80 in vector v.
            v.push_back(i);       
    }

    /*Random number generation.*/
    std::random_device rd;
    std::mt19937 g(rd());
    
    number_type numOfHits{0};   // Number of hits.
    float payout_rate{0};       // Payout Rate.
    cash_type result_wage{0};   // Resultant wage is the product of the bet wage times the payout rate.
    cash_type net_balance{m_credit}; // Player's net balance.

    /*Loop for the number of rounds.*/
    for(auto n{1}; n <= m_NR; n++){
        
        std::cout << "Please, hit enter for the next round.\n";
        getchar(); // Wait the player hits enter.
        
        m_draw.clear();

        /*Generates draw numbers for the round.*/
        std::shuffle(v.begin(), v.end(), g);
        std::copy(v.begin(), v.begin()+20,
              std::back_inserter(m_draw));
        std::sort(m_draw.begin(), m_draw.end()); // Sort draw numbers.

        std::cout << "  ____________________________________________________________ \n\n";
        std::cout << "  This is round #" << n << " of " << m_NR << ", and your wage is $" << bet.get_wage() << ". Good luck!\n\n";

        std::cout << "  The draw number are: [ ";        
        for(auto i:m_draw) std::cout << i << " ";       // Prints draw numbers.
        std::cout << "]\n";

        std::cout << "  Your original bet was: [ ";           
        for(auto i:bet.get_spots()) std::cout << i << " ";  // Prints original bet.
        std::cout << "]\n\n";

        numOfHits = bet.find_hits(m_draw).size();               // Stores the number of hits.

        std::cout << "  You hit the following number(s): [ ";        
        for(auto i:bet.find_hits(m_draw)) std::cout << i << " ";  // Prints the hits.
        std::cout << "], a total of " << numOfHits << " hits out of " << bet.size() << ".\n"; // Prints the number of hits out of the total possible hits.

        payout_rate = payout_table[bet.size()][numOfHits];
        result_wage = payout_rate*bet.get_wage();
        std::cout << "  Payout rate is " << payout_rate << ", thus you came out with: $" << result_wage << "\n\n";

        // m_credit = m_credit - bet.get_wage() + result_wage;
        net_balance += result_wage - bet.get_wage();
        std::cout << "  Your net balance so far is: $" << net_balance << "\n\n";
    }

    std::cout << "  ____________________________________________________________ \n\n";
    std::cout << "  End of rounds! \n\n";
    std::cout << "  ____________________________________________________________ \n\n";

    std::cout << "  ===== SUMARY =====\n"; 
    std::cout << " You spent in this game a total of $" << m_credit << ".\n";

    if(net_balance > m_credit){
        std::cout << " Hooray, you won $" << (net_balance - m_credit) << ". See you next time! ;-)\n";
    }
    else if(net_balance < m_credit){
        std::cout << " Too bad, you lost $" << (m_credit - net_balance) << ". Better luck next time.\n";
    }
    else std::cout << " Not a winner, but not a loser. You're ending with what you came. Come to play again another time.\n\n";

    std::cout << " You are leaving the Keno table with $" << net_balance << ".\n";
}


} // namespace Keno


//============[ End KenoGame class ]===============//