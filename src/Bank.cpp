/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** Bank
*/

#include "Bank.hpp"

Bank::Bank(std::string name) : _name(name)
{
        _siege = new t_b_type;
        _agency = new t_b_type;
        _siege->type = "siege";
        _agency->type = "agency";
        std::cout << "created bank " << _name << std::endl;
}

Bank::~Bank()
{
}

void            Bank::append_new_cat(std::string name)
{
        _siege->cat.push_back(new Categorie(name));
        _agency->cat.push_back(new Categorie(name));
        std::cout << "append cat " << name << " to bank " << _name << std::endl;
}

std::string     Bank::get_name()
{
        return _name;
}

void            Bank::set_name(std::string name)
{
        _name = name;
}

std::ostream     &operator<<(std::ostream &out, Bank *bank)
{
        out << "Bank: " << bank->get_name() << std::endl;
        out << "\tSiege Categories:" << std::endl;
        for (int i = 0; i < bank->_siege->cat.size(); i ++)
                out << "\t\t" << bank->_siege->cat.at(i)->get_name() << std::endl;
        out << "\tAgency Categories:" << std::endl;
        for (int i = 0; i < bank->_agency->cat.size(); i ++)
                out << "\t\t" << bank->_agency->cat.at(i)->get_name() << std::endl;
}