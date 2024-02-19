/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** Execution
*/

#include "Shell/Execution.hpp"

void nts::Execution::setState(const std::string &inputName, const std::string &value)
{
    IComponent *comp = this->_nano.getComponent(inputName);
    std::vector<std::string> inputNames = this->_nano.getInputNames();

    if (comp == nullptr) {
        throw nts::ShellError("Component not found: " + inputName);
    }
    if (std::find(inputNames.begin(), inputNames.end(), inputName) == inputNames.end()) {
        throw nts::ShellError("Component is not an input: " + inputName);
    }
    if (value == "0") {
        comp->setState(nts::Tristate::False);
    } else if (value == "1") {
        comp->setState(nts::Tristate::True);
    } else {
        comp->setState(nts::Tristate::Undefined);
    }
}

void nts::Execution::readCommand()
{
    std::cout << "> ";
    std::getline(std::cin, this->_command);

    if (std::cin.eof()) {
        this->_command = "exit";
    }
    Utils::trim(this->_command);
}

bool nts::Execution::execCommand()
{
    std::regex inputRegex("^(\\S+)=(0|1|U)$");
    std::smatch match;

    if (this->_command == "exit") {
        return true;
    }
    if (this->_command.find("=") != std::string::npos) {
        if (std::regex_match(this->_command, match, inputRegex)) {
            this->setState(match[1], match[2]);
            return false;
        } else {
            throw nts::ShellError("Invalid input=value format: " + this->_command);
        }
    }
    if (this->_commands.find(this->_command) != this->_commands.end()) {
        this->_commands[this->_command]();
        return false;
    } else {
        throw nts::ShellError("Unknown command: " + this->_command);
    }
}

void nts::Execution::run()
{
    bool exit = false;

    while (!exit) {
        try {
            this->readCommand();
            exit = this->execCommand();
        } catch (const nts::ShellError &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

nts::Execution::Execution(nts::NanoTekSpice &nano) : _nano(nano)
{
    this->_commands = {
        {"display", [&](){nano.display();}},
        {"simulate", [&](){nano.simulate();}},
        {"loop", [&](){nano.loop();}},
    };
}
