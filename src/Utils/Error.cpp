/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Error
*/

#include "Utils/Error.hpp"

nts::Error::Error(std::string const &message)
{
    this->_message = message;
}

const char *nts::Error::what() const noexcept
{
    return this->_message.c_str();
}

nts::ShellError::ShellError(std::string const &message)
{
    this->_message = message;
}

const char *nts::ShellError::what() const noexcept
{
    return this->_message.c_str();
}
