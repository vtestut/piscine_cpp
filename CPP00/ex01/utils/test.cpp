#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

std::string formatColumn(std::string str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}

int main() {
    std::vector<std::string> firstNames = {"Firstname", "John", "Jane", "LongFirstName"};
    std::vector<std::string> lastNames = {"Lastname", "Doe", "Doe", "LongLastName"};
    std::vector<std::string> nicknames = {"Nickname", "JD", "JD", "LongNickname"};

    for (size_t i = 0; i < firstNames.size(); ++i) {
        std::cout << std::right << std::setfill(' ')
                  << std::setw(10) << formatColumn(std::to_string(i), 10) << "|"
                  << std::setw(10) << formatColumn(firstNames[i], 10) << "|"
                  << std::setw(10) << formatColumn(lastNames[i], 10) << "|"
                  << std::setw(10) << formatColumn(nicknames[i], 10) << std::endl;
    }

    // Demandez à l'utilisateur l'index du contact à afficher...
    // Affichez les informations du contact...

    return 0;
}

int main() {
    // Crée un vecteur de chaînes de caractères
    std::vector<std::string> fruits;

    // Ajoute des éléments au vecteur
    fruits.push_back("Pomme");
    fruits.push_back("Banane");
    fruits.push_back("Orange");

    // Affiche le nombre d'éléments dans le vecteur
    std::cout << "Le vecteur contient " << fruits.size() << " éléments.\n";

    // Affiche chaque élément du vecteur
    for (int i = 0; i < fruits.size(); i++) {
        std::cout << "Fruit à l'index " << i << " : " << fruits[i] << "\n";
    }

    // Supprime le dernier élément du vecteur
    fruits.pop_back();

    // Affiche le nombre d'éléments dans le vecteur après la suppression
    std::cout << "Après suppression, le vecteur contient " << fruits.size() << " éléments.\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) : name(name), age(age) {}
};

int main() {
    // Crée un vecteur de Person
    std::vector<Person> people;

    // Ajoute des objets Person au vecteur
    people.push_back(Person("Alice", 30));
    people.push_back(Person("Bob", 40));

    // Affiche chaque personne du vecteur
    for (int i = 0; i < people.size(); i++) {
        std::cout << "Personne à l'index " << i << " : " << people[i].name << ", " << people[i].age << " ans\n";
    }

    return 0;
}