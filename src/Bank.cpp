/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** Bank
*/

#include "Bank.hpp"

Bank::Bank(std::string name) : _name(name)
{
}

Bank::~Bank()
{
}

std::vector<std::map<std::string, t_cat *>>            Bank::get_cat()
{
        return _cat;
}

void            Bank::append_cat(std::string name)
{
        auto                            map_it = _cat[0].end();
        std::map<std::string, t_cat *>  tmp;
        bool                            found = false;

        for (int i = 0; i < _cat.size(); i++)
        {
                map_it = _cat[i].find(name);
                if (map_it != _cat[i].end()) {
                        std::cout << "existing cat " << name << std::endl;
                        found = true;
                }
        }
        if (!found) {
                tmp[name] = new t_cat;
                _cat.push_back(tmp);
                std::cout << "created cat " << name << std::endl;
        }
}