/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** CircuitFile
*/

#pragma once

#include "Include.hpp"
#include "Utils/Utils.hpp"
#include "Utils/Error.hpp"

namespace nts {
    class CircuitFile {
        public:
            CircuitFile(std::string file);
            ~CircuitFile() = default;
            std::deque<std::pair<std::string, std::string>> getChipsets() const;
            std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> getLinks() const;

        private:
            void readChipsets(std::deque<std::string> &fileContent, size_t &pos);
            void readLinks(std::deque<std::string> &fileContent, size_t &pos);

            std::deque<std::pair<std::string, std::string>> _chipsets;
            std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> _links;

    };
}
