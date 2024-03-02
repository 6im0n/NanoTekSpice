/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** CircuitFile
*/

#include "Parsing/CircuitFile.hpp"

std::deque<std::pair<std::string, std::string>> nts::CircuitFile::getChipsets() const
{
    return this->_chipsets;
}

std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> nts::CircuitFile::getLinks() const
{
    return this->_links;
}

static void removeComment(std::deque<std::string> &fileContent)
{
    for (size_t i = 0; i < fileContent.size(); i++) {
        if (fileContent[i].find("#") != std::string::npos)
            fileContent[i] = fileContent[i].substr(0, fileContent[i].find("#"));
        Utils::trim(fileContent[i]);
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
        throw nts::Error("Error: invalid chipset line");
    chipset.first = match[1];
    chipset.second = match[2];
    return chipset;
}

void nts::CircuitFile::readChipsets(std::deque<std::string> &fileContent, size_t &pos)
{
    if (fileContent[pos] != ".chipsets:")
        throw nts::Error("Error: .chipsets: not found");
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
        throw nts::Error("Error: invalid link line");
    try {
        link.first.first = match[1];
        link.first.second = std::stoi(match[2]);
        link.second.first = match[3];
        link.second.second = std::stoi(match[4]);
    } catch (std::exception &e) {
        throw nts::Error("Error: invalid link line");
    }
    return link;
}

void nts::CircuitFile::readLinks(std::deque<std::string> &fileContent, size_t &pos)
{
    if (pos >= fileContent.size() || fileContent[pos] != ".links:")
        throw nts::Error("Error: .links: not found");
    for (pos = pos + 1; pos < fileContent.size(); pos++) {
        this->_links.push_back(getLink(fileContent[pos]));
    }
}

static void readLinesFromFile(std::string file, std::deque<std::string> &fileContent)
{
    std::ifstream ifs(file);
    std::string line;

    if (!ifs.is_open())
        throw nts::Error("Error: " + file + " file not found");
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
        throw nts::Error("Error: invalid file extension (should be .nts)");
    readLinesFromFile(file, fileContent);
    removeComment(fileContent);
    readChipsets(fileContent, pos);
    readLinks(fileContent, pos);
}
