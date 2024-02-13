/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Main
*/

#include "Include.hpp"
#include "Parsing/CircuitFile.hpp"

int display_help()
{
    std::cout << "\nUSAGE" << std::endl;
    std::cout << "\t./nanotekspice [path_to_file]" << std::endl;
    std::cout << "\nDESCRIPTION" << std::endl;
    std::cout << "\tpath_to_file\tpath to the configuration file.\n" << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-h") {
        return display_help();
    }
    if (ac != 2) {
        std::cerr << "Invalid number of arguments" << std::endl;
        std::cerr << "Try './nanotekspice -h' for more information." << std::endl;
        return 84;
    }
    try {
        nts::CircuitFile circuit(av[1]);
    } catch (nts::CircuitFile::FileError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
