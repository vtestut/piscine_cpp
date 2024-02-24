/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:33:41 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:24:33 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++)
                str[j] = std::toupper(str[j]);

            std::cout << str;
            if (i == argc - 1)
                std::cout << std::endl;
        }
    }
    else
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
