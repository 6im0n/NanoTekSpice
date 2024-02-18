/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoTekSpice.hpp"

void nts::NanoTekSpice::getDisplayContent()
{
    IComponent *compTemp = nullptr;

    this->_circuitInfo = "tick: " + std::to_string(this->ticks) + "\n";
    this->_circuitInfo += "input(s):\n";
    for (auto &input : this->_inputNames) {
        compTemp = this->getComponent(input);
        this->_circuitInfo += compTemp->getName() + ": " + compTemp->compute(1) + "\n";
    }
    this->_circuitInfo += "output(s):\n";
    for (auto &output : this->_outputNames) {
        compTemp = this->getComponent(output);
        this->_circuitInfo += compTemp->getName() + ": " + compTemp->compute(1) + "\n";
    }
}

void nts::NanoTekSpice::simulate()
{
    this->ticks++;
    this->getDisplayContent();
    for (auto &comp : this->_components) {
        comp->simulate(1);
    }
}

void nts::NanoTekSpice::display()
{
    std::cout << this->_circuitInfo;
}

void nts::NanoTekSpice::loop()
{
    bool sigint = false;

    while (!sigint) {
        this->simulate();
        this->display();
    }
}

nts::IComponent *nts::NanoTekSpice::getComponent(const std::string &name)
{
    for (auto &comp : this->_components) {
        if (comp->getName() == name)
            return comp.get();
    }
    throw nts::Error("Error: component not found");
}

std::vector<std::string> nts::NanoTekSpice::getInputNames() const
{
    return this->_inputNames;
}

std::unique_ptr<nts::IComponent> nts::NanoTekSpice::createComponent(const std::string &type, const std::string &name)
{
    static const std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &name)>> factory = {
        {"input", [](const std::string &name) { return std::make_unique<InputComponent>( InputComponent(name)); }},
        {"output", [](const std::string &name) { return std::make_unique<OutputComponent>( OutputComponent(name)); }},
        {"clock", [](const std::string &name) { return std::make_unique<ClockComponent>( ClockComponent(name)); }},
        {"true", [](const std::string &name) { return std::make_unique<TrueComponent>( TrueComponent(name)); }},
        {"false", [](const std::string &name) { return std::make_unique<FalseComponent>( FalseComponent(name)); }},
        {"and", [](const std::string &name) { return std::make_unique<AndComponent>( AndComponent(name)); }},
        {"or", [](const std::string &name) { return std::make_unique<OrComponent>( OrComponent(name)); }},
        {"xor", [](const std::string &name) { return std::make_unique<XorComponent>( XorComponent(name)); }},
        {"not", [](const std::string &name) { return std::make_unique<NotComponent>( NotComponent(name)); }},
        {"nor", [](const std::string &name) { return std::make_unique<NorComponent>( NorComponent(name)); }},
        {"nand", [](const std::string &name) { return std::make_unique<NandComponent>( NandComponent(name)); }},
        {"4001", [](const std::string &name) { return std::make_unique<C4001>( C4001(name)); }},
        {"4011", [](const std::string &name) { return std::make_unique<C4011>( C4011(name)); }},
        {"4030", [](const std::string &name) { return std::make_unique<C4030>( C4030(name)); }},
        {"4069", [](const std::string &name) { return std::make_unique<C4069>( C4069(name)); }},
        {"4071", [](const std::string &name) { return std::make_unique<C4071>( C4071(name)); }},
        {"4081", [](const std::string &name) { return std::make_unique<C4081>( C4081(name)); }},
    };

    if (factory.find(type) == factory.end())
        throw nts::Error("Unknown component type: " + type);
    if (type == "input" || type == "clock" || type == "true" || type == "false")
        this->_inputNames.push_back(name);
    if (type == "output")
        this->_outputNames.push_back(name);
    return factory.at(type)(name);
}

void nts::NanoTekSpice::setLink(const std::string &componentName, size_t pin, const std::string &otherComponentName, size_t otherPin)
{
    IComponent *component = this->getComponent(componentName);
    IComponent *otherComponent = this->getComponent(otherComponentName);

    if (component == nullptr || otherComponent == nullptr)
        throw nts::Error("Error: component not found");
    component->setLink(pin, *otherComponent, otherPin);
    otherComponent->setLink(otherPin, *component, pin);
}

nts::NanoTekSpice::NanoTekSpice(nts::CircuitFile &circuitFile)
{
    std::deque<std::pair<std::string, std::string>> chipsets = circuitFile.getChipsets();
    std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> links = circuitFile.getLinks();

    for (auto &chipset : chipsets) {
        this->_components.push_back(this->createComponent(chipset.first, chipset.second));
    }
    for (auto &link : links) {
        this->setLink(link.first.first, link.first.second, link.second.first, link.second.second);
    }
    if (this->_inputNames.empty() || this->_outputNames.empty())
        throw nts::Error("Error: missing input or output");
    this->ticks = 0;
    getDisplayContent();
}
