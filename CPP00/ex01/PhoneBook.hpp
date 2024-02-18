/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:45 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/18 23:50:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>

# include "Contact.hpp"

class PhoneBook {
	
public:
	Contact contacts_tab[8];

	PhoneBook();
	~PhoneBook();
	
	void	addContact();
	void	searchContact();
	void	exitContact();
	int		

private:
	int	_nbContacts;
	
};



#endif