/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:07:10 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 21:06:17 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define DEBUG	"DEBUG\t: Y'a anguille sous roche"
# define WARN	"WARNING\t: WOOP WOOP ASSASSIN DE LA POLICE"
# define INFO	"INFO\t: Did you know that Turks calls turkeys 'American birds'"
# define ERROR	"ERREUR\t: Qu'on lui couuuuuupe la tete !"

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
