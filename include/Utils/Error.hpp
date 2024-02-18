/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Error
*/

#pragma once

#include "Include.hpp"

namespace nts {
    class Error : public std::exception {
        public:
            Error(std::string const &message);
            const char *what() const noexcept override;

        private:
            std::string _message;
    };
}
