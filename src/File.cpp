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
        _data.resize(_size);
        if (!_fd.is_open())
                _data = "ERROR";
        else
                _fd.read(&_data[0], _size);
}

File::~File()
{
}

void            File::print()
{
        std::cout << _data << std::endl;
}

void            File::set_file(char *name)
{
        _name = name;
        _fd.open(_name);
        _fd.seekg(0, _fd.end);
        _size = _fd.tellg();
        _fd.seekg(0, _fd.beg);
        _data.resize(_size);
        if (!_fd.is_open())
                _data = "ERROR";
        else
                _fd.read(&_data[0], _size);
}

int             File::get_size()
{
        return _size;
}

std::string     File::get_name()
{
        return _name;
}

std::string     File::get_data()
{
        return _data;
}

void            File::find_categories()
{
        std::regex              reg_gen("((CATEGORIE |CAT )[0-9]+[A-Z]*|CAT[0-9]+[A-Z]*)");
        std::sregex_iterator    it_gen(_data.begin(), _data.end(), reg_gen);
        std::regex              reg_cat("[0-9]+[A-Z]*");
        std::sregex_iterator    end;
        std::smatch             match;
        int                     i = 0;
        Bank                    bank("test");

        while (it_gen != end) {
                match = *it_gen;
                std::sregex_iterator    it_cat(match.str().begin(), match.str().end(), reg_cat);
                match = *it_cat;
                std::cout << match.str() << "\t";
                bank.append_cat(match.str());
                ++it_gen;
        }
        std::cout << bank.get_cat().size() << std::endl;
}

auto            File::find_banks()
{

}