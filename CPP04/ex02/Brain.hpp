/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:31:31 by mcombeau          #+#    #+#             */
/*   Updated: 2024/03/20 16:47:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &	operator=(Brain const & src);

		std::string const &	getIdea(int index) const;
		void				setIdea(int index, std::string const & idea);

		static int const	nb_ideas = 100;

	private:
		std::string	_ideas[nb_ideas];
};

#endif
