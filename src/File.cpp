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

void            File::print()
{
        std::cout << _data << std::endl;
}