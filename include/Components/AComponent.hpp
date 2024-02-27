/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** AComponent
*/

#pragma once

#include "Components/IComponent.hpp"
#include <deque>

namespace nts {
    class AComponent : public IComponent {
    public:
        AComponent(size_t size, const std::string &name);
        ~AComponent() = default;
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) override;
        void setState(nts::Tristate state) override;
        std::string getName() const override;
        void checkIfNotLoop();
    protected:
        std::string _name;
        size_t _ticks;
        std::deque<IComponent*> _links;
        std::deque<size_t> _pins;
        size_t loop;
    };
}
