#ifndef CLASS_INSTANCE_HPP
# define CLASS_INSTANCE_HPP

# include <iostream>

class MyClass {

public:

    int     foo;
    int     *bar;

    MyClass( void );
    ~MyClass( void );

    void    func( void );

};

#endif