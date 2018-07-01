/*
** EPITECH PROJECT, 2018
** simulator
** File description:
** Categorie
*/

#ifndef CATEGORIE_HPP_
	#define CATEGORIE_HPP_

#include <iostream>
#include <string>

class Categorie {
public:
        Categorie(std::string name);
        ~Categorie();

        std::string             get_name();

        friend std::ostream     &operator << (std::ostream &out, Categorie *cat);

protected:
        std::string             _name;
private:
};

#endif /* !CATEGORIE_HPP_ */