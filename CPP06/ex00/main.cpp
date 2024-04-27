/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:57:02 by vtestut          #+#    #+#             */
/*   Updated: 2022/08/11 13:27:19 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 ) {
        std::cout << "Usage: ./convert number" << std::endl;
        return EXIT_FAILURE;
    }

    Converter c;

    try
    {
        c.setStr( av[1] );
        c.convert();

        std::cout << c;
    }
    catch( const std::exception& e ) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return EXIT_SUCCESS;
}