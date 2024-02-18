#ifndef CONST_HPP
# define CONST_HPP

#include <iostream>

class Sample {

public:
	
	float const pi;
	int			qd;

/*	
*	Je peux initialiser une variable const via le constructeur */
	Sample(float const f);
	~Sample(void);

/*
*	Quand une fonction membre est déclarée const, 
*	elle ne peut pas modifier les attributs de l'objet. */
	void	bar(void) const;

};

#endif