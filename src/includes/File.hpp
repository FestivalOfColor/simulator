/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** File
*/

#include <string>
#include <fstream>
#include <iostream>

#ifndef FILE_HPP_
	#define FILE_HPP_

class File {
public:
	File();
	File(char *name);
	~File();

	void		set_file(char *name);
	void		print();

protected:
private:
	std::string	_name;
	std::ifstream	_fd;
	int		_size;
	std::string	_data;
};

#endif /* !FILE_HPP_ */
