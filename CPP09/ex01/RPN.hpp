#ifndef _RPN_HPP
# define _RPN_HPP

# include <iostream>
# include <deque>
# include <string>
# include <stdexcept>
# include <algorithm>

# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define CYAN   "\033[36m"
# define YELLOW "\033[93m"
# define RESET  "\033[0m"

class RPN {

    private:

    std::deque<float> deque;

    RPN();

    public:
    
    RPN(std::string arg);
    RPN(const RPN & other);
    RPN& operator=(const RPN & other);
    
    ~RPN();
    

    void run();
};

#endif