/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virgile <virgile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:45 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/19 04:26:35 by virgile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <vector>

# include "Contact.hpp"

# define MAXCNTCT 3
# define LASTCNTCT 2

class PhoneBook {
	
public:
	Contact contacts_tab[MAXCNTCT];

	PhoneBook();
	~PhoneBook();
	
	void	addContact();
	void	searchContact();
	void	exitContact();
	std::string formatColumn(std::string str, size_t width);
	std::string to_str(int i);


	int		getNbContacts();
	void	setNbContacts();
	
private:
	int	_nbContacts;
	
};



#endif