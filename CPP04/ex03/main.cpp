#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

static void displayTitle(std::string title) {
	std::cout << std::endl << std::endl << std::endl;
	std::cout << CYAN << "********** " << title << RESET << std::endl;
	std::cout << std::endl;
}

static void subjectMain() {
    displayTitle("SUBJECT MAIN");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
}

static void fullMain() {
    displayTitle("OVERFLOWED MATERIASOURCE");
    MateriaSource *src = new MateriaSource();
    std::cout << *src;
    src->learnMateria(new Ice());
    src->learnMateria(NULL);
    src->learnMateria(new Cure());
    std::cout << *src;
    
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    std::cout << *src;

    displayTitle("USE");
    Character *gandoulf = new Character("Gandoulf");
    Character *dobby = new Character("Dobby");
    AMateria *tmp1;
    AMateria *tmp2;
    AMateria *tmp3;

    tmp1 = src->createMateria("ice");
    gandoulf->equip(tmp1);
    tmp2 = src->createMateria("cure");
    gandoulf->equip(tmp2);
    tmp1 = src->createMateria("fire");

    gandoulf->use(0, *dobby);
    gandoulf->use(1, *dobby);
    gandoulf->use(2, *dobby);
    gandoulf->use(-1, *dobby);
    gandoulf->use(4, *dobby);
    
    std::cout << *gandoulf;
    std::cout << *dobby;

    displayTitle("DEEP COPY CHARACTER");
    Character *merlin = new Character("Merlin");

    tmp3 = src->createMateria("cure");
    merlin->equip(tmp3);
    merlin->equip(src->createMateria("ice"));
    merlin->equip(src->createMateria("earth"));
    
    Character *merlin_copy = new Character(*merlin);
    
    merlin->unequip(0);
    merlin_copy->equip(src->createMateria("cure"));
    merlin_copy->equip(src->createMateria("ice"));
    merlin->use(0, *dobby);
    merlin->use(1, *dobby);
    merlin->use(2, *dobby);
    merlin->use(3, *dobby);
    
    merlin_copy->use(0, *dobby);
    merlin_copy->use(1, *dobby);
    merlin_copy->use(2, *dobby);
    merlin_copy->use(3, *dobby);

    displayTitle("DROP ITEM");
    std::cout << *gandoulf;
    gandoulf->unequip(1);
    gandoulf->unequip(3);
    gandoulf->unequip(4);
    gandoulf->use(1, *merlin);
    gandoulf->equip(src->createMateria("cure"));
    std::cout << *gandoulf;

    displayTitle("FULL INVENTORY");
    gandoulf->equip(src->createMateria("cure"));
    gandoulf->equip(src->createMateria("cure"));
    gandoulf->equip(src->createMateria("ice"));
    std::cout << *gandoulf;
    std::cout << std::endl;

    delete dobby;
    delete gandoulf;
    delete src;
    delete merlin;
    delete merlin_copy;
    delete tmp1;
    delete tmp2;
    delete tmp3;
}

int main() {
    subjectMain();
    fullMain();
}