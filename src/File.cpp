/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** File
*/

#include "File.hpp"

File::File()
{

}

File::File(char *name) : _name(name)
{
        _fd.open(_name);
        _fd.seekg(0, _fd.end);
        _size = _fd.tellg();
        _fd.seekg(0, _fd.beg);
        _volumes.resize(_size);
        if (!_fd.is_open())
                _volumes = "ERROR";
        else
                _fd.read(&_volumes[0], _size);
}

File::~File()
{
}

void            File::print_volumes()
{
        std::cout << _volumes << std::endl;
}

void            File::print_banks()
{
        std::cout << "_banks size: " << _banks.size() << std::endl;
        for (int i = _banks.size() - 1; i >= 0; i--)
                std::cout << _banks.at(i) << std::endl << std::endl;
}

void            File::set_file(char *name)
{
        _name = name;
        _fd.open(_name);
        _fd.seekg(0, _fd.end);
        _size = _fd.tellg();
        _fd.seekg(0, _fd.beg);
        _volumes.resize(_size);
        if (!_fd.is_open())
                _volumes = "ERROR";
        else
                _fd.read(&_volumes[0], _size);
}

int             File::get_size()
{
        return _size;
}

std::string     File::get_name()
{
        return _name;
}

std::string     File::get_volumes()
{
        return _volumes;
}

void            File::find_categories(Bank *bank)
{
        std::regex                      reg_gen("((CATEGORIE |CAT )[0-9]+[A-Z]*|CAT[0-9]+[A-Z]*)");
        std::sregex_iterator            it_gen(_volumes.begin(), _volumes.end(), reg_gen);
        std::regex                      reg_cat("[0-9]+[A-Z]*");
        std::sregex_iterator            end;
        std::smatch                     match;
        int                             i = 0;
        std::vector<std::string>        all_cat;

        while (it_gen != end) {
                match = *it_gen;
                std::sregex_iterator    it_cat(match.str().begin(), match.str().end(), reg_cat);
                match = *it_cat;
                add_cat(&all_cat, match.str());
                ++it_gen;
        }
        for (int i = 0; i < all_cat.size(); i ++)
                bank->append_new_cat(all_cat[i]);
}

void            File::add_cat(std::vector<std::string> *cat, std::string match)
{
        auto    res = std::find(std::begin(*cat), std::end(*cat), match);

        if (res == std::end(*cat))
                cat->push_back(match);
}

void            File::find_banks()
{
        std::regex                      reg_bank(",\"[ ]*(BP|CE)[A-Za-z]+[ ]*\",");
        std::sregex_iterator            it_bank(_volumes.begin(), _volumes.end(), reg_bank);
        std::regex                      reg_name("[A-Za-z]+");
        std::sregex_iterator            end;
        std::smatch                     match;
        std::vector<std::string>        all_banks;

        while (it_bank != end) {
                match = *it_bank;
                std::sregex_iterator    it_name(match.str().begin(), match.str().end(), reg_name);
                match = *it_name;
                add_bank(&all_banks, match.str());
                ++it_bank;
        }
        for (int i = 0; i < all_banks.size(); i ++)
                _banks.push_back(new Bank(all_banks[i]));
        for (int i = 0; i < _banks.size(); i ++)
                find_categories(_banks[i]);
}

void            File::add_bank(std::vector<std::string> *banks, std::string match)
{
        auto    res = std::find(std::begin(*banks), std::end(*banks), match);

        if (res == std::end(*banks))
                banks->push_back(match);
}