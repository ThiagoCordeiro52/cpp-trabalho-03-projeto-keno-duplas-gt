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
    return false;
}

bool KenoBet::set_wage( Keno::cash_type wage )
{
    // TODO
    return false;
}

void KenoBet::reset( void )
{
    // TODO
}

Keno::cash_type KenoBet::get_wage( void ) const
{
    // TODO
    return 0;
}

size_t KenoBet::size( void ) const
{
    // TODO
    return 0;
}

Keno::set_of_numbers_type
KenoBet::find_hits( const Keno::set_of_numbers_type & draw ) const
{
    // This container will store all common elements, if any exists.
    Keno::set_of_numbers_type intersection;

    // TODO

    // Return final count.
    return intersection;
}

Keno::set_of_numbers_type
KenoBet::get_spots( void ) const
{
    // TODO
    Keno::set_of_numbers_type dummy;
    return dummy;
}

} // namespace Keno


//============[ End KenoBet class ]===============//
