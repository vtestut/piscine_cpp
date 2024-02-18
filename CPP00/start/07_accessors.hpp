#ifndef ACCESSORS_HPP
# define ACCESSORS_HPP

# include <iostream>


class MyClass {

public:

	MyClass(int v);
	~MyClass(void);

/*
*	Un accesseur est une méthode qui permet d'accéder à un attribut privé de la classe.	*/
	int		getFoo(void) const;
	void	setFoo(int n);
	int		compareFoo(MyClass *other) const;

private:

	int		_foo;

};


#endif