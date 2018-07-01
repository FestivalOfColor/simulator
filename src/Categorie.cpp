/*
** EPITECH PROJECT, 2018
** simulator
** File description:
** Categorie
*/

#include "Categorie.hpp"

Categorie::Categorie(std::string name) : _name(name)
{
}

Categorie::~Categorie()
{
}

std::string            Categorie::get_name()
{
        return _name;
}

std::ostream            &operator << (std::ostream &out, Categorie *cat)
{
        out << "Category: " << cat->get_name();
}