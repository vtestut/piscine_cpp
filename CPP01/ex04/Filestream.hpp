/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:53:42 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:53:45 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

class Filestream {

	public:

		Filestream(const char *p1);

		int replace(std::string s1, std::string s2);

	private:

		const char *_name;
};

#endif
