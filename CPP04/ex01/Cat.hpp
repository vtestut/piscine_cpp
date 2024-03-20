/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:17:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/20 16:56:44 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _CAT_HPP
# define _CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat & obj);
	
	~Cat();

	void makeSound() const;
	Brain *	getBrain(void) const; // NEW

	Cat & operator=(const Cat & obj);

private:

		Brain *	_brain; // NEW

};

#endif