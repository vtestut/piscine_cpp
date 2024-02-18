#ifndef NON_MEMBRE_HPP
# define NON_MEMBRE_HPP

# include <iostream>

class MyClass {

public:

	MyClass();
	~MyClass();

/*
*	declarer une fonction en static permet de l'appeler sans instancier la classe, 
*	elle est partagee par toutes les instances de la classe,
*	elle ne peut pas acceder aux membres non static de la classe,
*	elle ne peut pas etre declaree const ne peut faire appel au ptr this->*/
	static int getNbInstances(void);

private:

	static int _nbInstances;
};

#endif