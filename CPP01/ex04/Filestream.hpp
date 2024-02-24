/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:53:42 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 22:57:33 by v                ###   ########.fr       */
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
