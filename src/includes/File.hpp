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
#include <algorithm>

#include "Bank.hpp"

class File {
public:
	File();
	File(char *name);
	~File();

	void		print_volumes();
	void		print_banks();
	void		find_categories(Bank *bank);
	void		add_cat(std::vector<std::string> *cat, std::string match);
	void		find_banks();
	void		add_bank(std::vector<std::string> *banks, std::string match);

	void		set_file(char *name);

	int		get_size();
	std::string	get_name();
	std::string	get_volumes();

protected:
private:
	std::string		_name;
	std::ifstream		_fd;
	int			_size;
	std::string		_volumes;
	std::vector<Bank *>	_banks;
};

#endif /* !FILE_HPP_ */
