/*
** EPITECH PROJECT, 2024
** BootStrap NTS
** File description:
** Component
*/

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "Tristate.hpp"

namespace nts {
    class IComponent {
    public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
        virtual nts::Tristate getLink(std::size_t pin) = 0;
        virtual void setState(nts::Tristate state) = 0;
    };
}
