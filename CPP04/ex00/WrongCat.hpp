/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:32:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:33:32 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _WRONGCAT_HPP
# define _WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

public:

	WrongCat();
	WrongCat(const WrongCat & obj);
	~WrongCat();

	void makeSound() const;

	WrongCat & operator=(const WrongCat & obj);

};

#endif
