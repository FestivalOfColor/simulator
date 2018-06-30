/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** Bank
*/

#ifndef BANK_HPP_
	#define BANK_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <map>

typedef struct	s_cat {
	std::string					name;
	std::vector<std::map<std::string, int>>		volumes;
}		t_cat;

class Bank {
public:
	Bank(std::string name);
	~Bank();

	std::string						get_name();
	std::vector<std::map<std::string, t_cat *>>		get_cat();

	void							set_name(std::string);

	void							append_cat(std::string name);

protected:
private:
	std::string					_name;
	std::vector<std::map<std::string, t_cat *>>	_cat;
};

#endif /* !BANK_HPP_ */
