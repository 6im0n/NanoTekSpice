/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Acomponent
*/

#pragma once
#include "Icomponent.hpp"

namespace nts {
    class Acomponent : public IComponent {
    public:
        Acomponent();
        Acomponent(size_t);
        ~Acomponent();
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        nts::Tristate getLink(std::size_t pin) override;
        void setState(nts::Tristate state) override {(void)state;};
    protected:
        std::vector<IComponent*> _links;
        std::vector<size_t> _pins;
    };
}
