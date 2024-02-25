/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 07:54:46 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWoutput_HPP
# define NEWoutput_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <iterator>

# define INCLUD "#include XXX"
# define IFNDEF "#ifndef XXX"
# define DEFINE "# define XXX"

class NewClass {

public:

    void generateFiles(const std::string& className, bool do_makefile);

private:

    void _generateHeader(const std::string& path, const std::string& filename);
    void _generateSource(const std::string& path, const std::string& filename);
    void _generateMakefile(const std::string& path, const std::string& filename);
    void _replaceAll(std::string& str, const std::string& from, const std::string& to);
    // bool _isFirstLetterUppercase(const std::string& str);
    void capitalizeFirstLetter(std::string& str);
    void toUpperCase(std::string& str);
};

#endif