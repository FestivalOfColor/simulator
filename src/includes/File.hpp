/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** File
*/


#ifndef FILE_HPP_
	#define FILE_HPP_

#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "Bank.hpp"

class File {
public:
	File();
	File(char *name);
	~File();

	void		print();
	void		find_categories();
	auto		find_banks();

	void		set_file(char *name);

	int		get_size();
	std::string	get_name();
	std::string	get_data();

protected:
private:
	std::string		_name;
	std::ifstream		_fd;
	int			_size;
	std::string		_data;
	std::vector<Bank *>	_banks;
};

#endif /* !FILE_HPP_ */
