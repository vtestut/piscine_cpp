/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:50 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 18:09:37 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cassert>

int main( void )
{
	std::cout << "Main tests :\n" << std::endl;
	
	Fixed r;
	Fixed const s( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << r << std::endl;
	std::cout << ++r << std::endl;
	std::cout << r << std::endl;
	std::cout << r++ << std::endl;
	std::cout << r << std::endl;

	std::cout << s << std::endl;

	std::cout << Fixed::max( r, s ) << std::endl;
	
	/*************************************************/

	std::cout << "\nMy tests :\n" << std::endl;
	
    // default constructor
    Fixed a;
    assert(a.toFloat() == 0.0f);
	assert(a.toInt() == 0);

    // int constructor
    Fixed b(10);
    assert(b.toFloat() == 10.0f);
	assert(b.toInt() == 10);

    // float constructor
    Fixed c(5.5f);
    assert(c.toFloat() == 5.5f);
	assert(c.toInt() == 5);

    // arithmetic operators
    Fixed d = b + c;
    assert(d == b.toFloat() + c.toFloat());

    Fixed e = b - c;
    assert(e == b.toFloat() - c.toFloat());

    Fixed f = d * c;
    assert(f == d.toFloat() * c.toFloat());

	Fixed g = d / c;
	assert(g ==  d.toFloat() / c.toFloat());

	// comparison operators
    Fixed h(15.5f);
    assert(d == h);
    assert(d >= h);
    assert(d+c >= h);
    assert(d <= h);
    assert(c <= h);
    assert(d > e);
    assert(e < d);
    assert(e != h);

    //	Pre/De-crementation operators
    Fixed i(4.2f);

	Fixed j = (++Fixed(i));
	assert(j == ++i);
	
	Fixed k = (--Fixed(i));
	assert(k == --i);
	
	Fixed l = (Fixed(i)++);
	assert(l == i++);
	
	Fixed m = (Fixed(i)--);
	assert (m == i--);

    // min / max
    Fixed n(3.3f);
    Fixed o(4.4f);
    Fixed p = Fixed::min(n, o);
    assert(p == n);
    Fixed q = Fixed::max(n, o);
    assert(q == o);

    // min / max  const
    const Fixed cn(1);
    const Fixed co(2);
    const Fixed cp = Fixed::min(cn, co);
    assert(cp == cn);
    const Fixed cq = Fixed::max(cn, co);
    assert(cq == co);

    std::cout << "Insertion operator test : d = " << d << std::endl;

    std::cout << "All tests validated !" << std::endl;

    return 0;
}