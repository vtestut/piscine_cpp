/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:11 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 21:14:39 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define DEBUG	"[ DEBUG ]\nY'a anguille sous roche"
# define WARN	"[ WARNING ]\nWOOP WOOP ASSASSIN DE LA POLICE"
# define INFO	"[ INFO ]\nDid you know that Turks calls turkeys 'American birds'"
# define ERROR	"[ ERREUR ]\nQu'on lui couuuuuupe la tete !"

class Harl {

	public: 

		void complain(std::string level);
		
	private:
		
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif