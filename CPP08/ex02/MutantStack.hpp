#ifndef  _MUTANTSTACK_HPP
# define _MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <vector>
# include <deque>

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
/*									CLASS									  */
/******************************************************************************/

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

public :

	MutantStack() : std::stack<T, Container>() {}
	MutantStack(const MutantStack& obj) : std::stack<T, Container>(obj) {}
	
	~MutantStack() {}

	MutantStack& operator=(const MutantStack& obj) {
		if (this != &obj)
			std::stack<T, Container>::operator=(obj);
		return *this;
	}

	typedef typename Container::iterator				iterator;
	typedef typename Container::const_iterator			const_iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;

	iterator				begin()			{return this->c.begin();}
	iterator				end()			{return this->c.end();}
	
	const_iterator			begin()	const	{return this->c.begin();}
	const_iterator			end() const		{return this->c.end();}
	
	reverse_iterator		rbegin()		{return this->c.rbegin();}
	reverse_iterator		rend()			{return this->c.rend();}
	
	const_reverse_iterator	rbegin() const	{return this->c.rbegin();}
	const_reverse_iterator	rend() const 	{return this->c.rend();}
};

template <typename InputIterator>
void printIterator(InputIterator begin, InputIterator end) {
	std::cout << CYAN "{";
	bool is_first = true;
	for (InputIterator it = begin; it != end; ++it) {
		if (is_first)
			is_first = false;
		else 
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "}" RESET << std::endl;
}

#endif
