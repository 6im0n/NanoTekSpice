/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** CircuitFile
*/

#pragma once

#include "Include.hpp"
#include "Utils/Utils.hpp"

namespace nts {
    class CircuitFile {
        public:
            CircuitFile(std::string file);
            ~CircuitFile() = default;

            class FileError : public std::exception {
                public:
                    FileError(std::string const &message);
                    const char *what() const noexcept override;

                private:
                    std::string _message;
            };

        private:
            void readChipsets(std::deque<std::string> &fileContent, size_t &pos);
            void readLinks(std::deque<std::string> &fileContent, size_t &pos);

            std::deque<std::pair<std::string, std::string>> _chipsets;
            std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> _links;

    };
}
