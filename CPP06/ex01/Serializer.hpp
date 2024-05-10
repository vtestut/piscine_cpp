#ifndef  _SERIALIZER_HPP
# define _SERIALIZER_HPP

# include <iostream> 
# include <string>
# include <stdint.h>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									STRUCT									  */
/******************************************************************************/

struct Data {
	std::string	str;
	int			n;
};

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Serializer {

private:

	Serializer() {};
	Serializer(const Serializer& obj);
	Serializer & operator=(const Serializer& obj);

public:

	~Serializer() {};

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
