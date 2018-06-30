/*
** EPITECH PROJECT, 2018
** simulateur
** File description:
** main
*/

#include "File.hpp"

void    help()
{
        std::cout << "HELP" << std::endl;
        std::cout << "./simulator [volume_data.csv]" << std::endl;
}

int     main(int ac, char **av)
{
        File    file;

        if (!av[1]) {
                help();
                return 1;
        }
        file.set_file(av[1]);
}