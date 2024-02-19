/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** NanoTekSpice
*/

#pragma once

#include "Include.hpp"
#include "Parsing/CircuitFile.hpp"
#include "Components/ComponentsInclude.hpp"

namespace nts {
    class NanoTekSpice {
        public:
            NanoTekSpice(nts::CircuitFile &circuitFile);
            ~NanoTekSpice() = default;
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &name);
            void setLink(const std::string &componentName, size_t pin, const std::string &otherComponentName, size_t otherPin);
            void simulate();
            void display();
            void loop();
            nts::Tristate getOutput(const std::string &outputName);
            nts::IComponent *getComponent(const std::string &name);
            std::vector<std::string> getInputNames() const;

        private:
            void getDisplayContent();

            size_t ticks;
            std::vector<std::unique_ptr<nts::IComponent>> _components;
            std::vector<std::string> _inputNames;
            std::vector<std::string> _outputNames;
            std::string _circuitInfo;
    };
}
