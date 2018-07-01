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

#include "Categorie.hpp"

typedef struct	s_bank_type {
	std::string			type;
	std::vector<Categorie *>	cat;
}		t_b_type;

class Bank {
public:
	Bank(std::string name);
	~Bank();
	void			append_new_cat(std::string cat_name);

	std::string		get_name();

	void			set_name(std::string);

	friend std::ostream		&operator << (std::ostream &out,Bank *bank);

protected:
private:
	std::string		_name;
	t_b_type		*_siege;
	t_b_type		*_agency;
};

#endif /* !BANK_HPP_ */
