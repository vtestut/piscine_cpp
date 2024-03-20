/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:12:27 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/20 16:55:03 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _DOG_HPP
# define _DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog & obj);
	
	~Dog();

	void makeSound() const;
	Brain *	getBrain(void) const; // NEW

	Dog & operator=(const Dog & obj);

private:

		Brain *	_brain; // NEW

};

#endif
