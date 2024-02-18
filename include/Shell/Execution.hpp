/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Execution
*/

#pragma once

#include "Include.hpp"
#include "NanoTekSpice.hpp"

namespace nts {
    class Execution {
        public:
            Execution(nts::NanoTekSpice &nano);
            ~Execution() = default;
            void run();

        private:
            void readCommand();
            bool execCommand();
            void setState(const std::string &inputName, const std::string &value);
            std::unordered_map<std::string, std::function<void()>> _commands;
            std::string _command;
            nts::NanoTekSpice &_nano;

    };
}
