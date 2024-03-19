/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:12:27 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:13:08 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _DOG_HPP
# define _DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog & obj);
	
	~Dog();

	void makeSound() const;

	Dog & operator=(const Dog & obj);

};

#endif
