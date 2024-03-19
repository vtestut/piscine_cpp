/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:17:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:17:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _CAT_HPP
# define _CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat & obj);
	
	~Cat();

	void makeSound() const;

	Cat & operator=(const Cat & obj);

};

#endif