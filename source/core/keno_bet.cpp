/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file keno_bet.cpp
 *
 */

#include "keno_bet.h"

namespace Keno {

bool KenoBet::add_spot( Keno::number_type spot )
{
    // TODO

    if(!std::binary_search( m_spots.begin(), m_spots.end(), spot ) ){  // If number is not already in player's spot do the following.
        m_spots.push_back(spot); // Adds the number to the player's spot.
        return true;
    }
    return false;
}

bool KenoBet::set_wage( Keno::cash_type wage )
{
    // TODO

    if(wage > 0){ // If wage is above zero do the following.
        m_wage = wage; // Set the amount of money the player is betting.
        return true;
    }
    return false;
}

void KenoBet::reset( void )
{
    // TODO

    m_spots.clear();
}

Keno::cash_type KenoBet::get_wage( void ) const
{
    // TODO
    
    return m_wage;

    // return 0;
}

size_t KenoBet::size( void ) const
{
    // TODO

    return m_spots.size();

    // return 0;
}

Keno::set_of_numbers_type
KenoBet::find_hits( const Keno::set_of_numbers_type & draw ) const
{
    // This container will store all common elements, if any exists.
    Keno::set_of_numbers_type intersection;

    // TODO

    std::set_intersection(draw.begin(), draw.end(), m_spots.begin(), m_spots.end(), std::back_inserter(intersection) );

    // Return final count.
    return intersection;
}

Keno::set_of_numbers_type
KenoBet::get_spots( void ) const
{
    // TODO
    
    return m_spots;
    
    // Keno::set_of_numbers_type dummy;
    // return dummy;
}

} // namespace Keno


//============[ End KenoBet class ]===============//
