/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 04:16:39 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWCLASS_HPP
# define NEWCLASS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


class NewClass {

public:

    void generateFiles(	const std::string& headerFile, const std::string& sourceFile, bool  do_makefile);

private:

    void _generateHeader(const std::string& path, const std::string& filename);
    void _generateSource(const std::string& path, const std::string& filename);
    void _generateMakefile(const std::string& path);
};

#endif