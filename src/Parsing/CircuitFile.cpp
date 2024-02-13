/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** CircuitFile
*/

#include "Parsing/CircuitFile.hpp"

static void removeComment(std::deque<std::string> &fileContent)
{
    for (size_t i = 0; i < fileContent.size(); i++) {
        if (fileContent[i].find("#") != std::string::npos)
            fileContent[i] = fileContent[i].substr(0, fileContent[i].find("#"));
        Utils::trimEnd(fileContent[i]);
        if (fileContent[i].empty()) {
            fileContent.erase(fileContent.begin() + i);
            i--;
        }
    }
}

static std::pair<std::string, std::string> getChipset(std::string line)
{
    std::pair<std::string, std::string> chipset;
    std::regex reg("^(\\S+)[\t ]+(\\S+)$");
    std::smatch match;

    if (!std::regex_match(line, match, reg))
        throw nts::CircuitFile::FileError("Error: invalid chipset line");
    chipset.first = match[1];
    chipset.second = match[2];
    return chipset;
}

void nts::CircuitFile::readChipsets(std::deque<std::string> &fileContent, size_t &pos)
{
    if (fileContent[pos] != ".chipsets:")
        throw nts::CircuitFile::FileError("Error: .chipsets: not found");
    for (pos = 1; pos < fileContent.size() && fileContent[pos] != ".links:"; pos++) {
        this->_chipsets.push_back(getChipset(fileContent[pos]));
    }
}

static std::pair<std::pair<std::string, int>, std::pair<std::string, int>> getLink(std::string line)
{
    std::pair<std::pair<std::string, int>, std::pair<std::string, int>> link;
    std::regex reg("^(\\S+):(\\d+)[\t ]+(\\S+):(\\d+)$");
    std::smatch match;

    if (!std::regex_match(line, match, reg))
        throw nts::CircuitFile::FileError("Error: invalid link line");
    try {
        link.first.first = match[1];
        link.first.second = std::stoi(match[2]);
        link.second.first = match[3];
        link.second.second = std::stoi(match[4]);
    } catch (std::exception &e) {
        throw nts::CircuitFile::FileError("Error: invalid link line");
    }
    return link;
}

void nts::CircuitFile::readLinks(std::deque<std::string> &fileContent, size_t &pos)
{
    if (pos >= fileContent.size() || fileContent[pos] != ".links:")
        throw nts::CircuitFile::FileError("Error: .links: not found");
    for (pos = pos + 1; pos < fileContent.size(); pos++) {
        this->_links.push_back(getLink(fileContent[pos]));
    }
}

static void readLinesFromFile(std::string file, std::deque<std::string> &fileContent)
{
    std::ifstream ifs(file);
    std::string line;

    if (!ifs.is_open())
        throw nts::CircuitFile::FileError("Error: " + file + " file not found");
    while (std::getline(ifs, line)) {
        fileContent.push_back(line);
    }
    ifs.close();
}

nts::CircuitFile::CircuitFile(std::string file)
{
    std::deque<std::string> fileContent;
    size_t pos = 0;

    if (file.substr(file.find_last_of(".") + 1) != "nts")
        throw nts::CircuitFile::FileError("Error: invalid file extension (should be .nts)");
    readLinesFromFile(file, fileContent);
    removeComment(fileContent);
    readChipsets(fileContent, pos);
    readLinks(fileContent, pos);
}

nts::CircuitFile::FileError::FileError(std::string const &message)
{
    this->_message = message;
}

const char *nts::CircuitFile::FileError::what() const noexcept
{
    return this->_message.c_str();
}
