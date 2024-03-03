/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestCircuitFile
*/

#include "Parsing/CircuitFile.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(CircuitFile, testWrongExtension)
{
    cr_assert_throw(nts::CircuitFile file("WrongExtension.txt"), nts::Error);
}

Test(CircuitFile, testEmptyFile)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/EmptyFile.nts"), nts::Error);
}

Test(CircuitFile, testFileNotFound)
{
    cr_assert_throw(nts::CircuitFile file("FileNotFound.nts"), nts::Error);
}

Test(CircuitFile, testChipsetsNotFound)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/ChipsetsNotFound.nts"), nts::Error);
}

Test(CircuitFile, testInvalidChipsetLine)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/InvalidChipsetLine.nts"), nts::Error);
}

Test(CircuitFile, testLinksNotFound)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/LinksNotFound.nts"), nts::Error);
}

Test(CircuitFile, testInvalidLinkLine)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/InvalidLinkLine.nts"), nts::Error);
}

Test(CircuitFile, testInvalidLinkPin)
{
    cr_assert_throw(nts::CircuitFile file("TestFile/NtsFailing/InvalidLinkPin.nts"), nts::Error);
}

Test(CircuitFile, testBasicValidFile)
{
    nts::CircuitFile *file = new nts::CircuitFile("TestFile/NtsSingle/and.nts");

    cr_assert_not_null(file);
}

Test(CircuitFile, testGetterChipsets)
{
    nts::CircuitFile *file = new nts::CircuitFile("TestFile/NtsSingle/true.nts");
    std::deque<std::pair<std::string, std::string>> chipsets = file->getChipsets();

    cr_assert_eq(chipsets.size(), 2);
    cr_assert_str_eq(chipsets[0].first.c_str(), "true");
    cr_assert_str_eq(chipsets[0].second.c_str(), "in");
    cr_assert_str_eq(chipsets[1].first.c_str(), "output");
    cr_assert_str_eq(chipsets[1].second.c_str(), "out");
    delete file;
}

Test(CircuitFile, testGetLinks)
{
    nts::CircuitFile *file = new nts::CircuitFile("TestFile/NtsSingle/true.nts");
    std::deque<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> links = file->getLinks();

    cr_assert_eq(links.size(), 1);
    cr_assert_str_eq(links[0].first.first.c_str(), "in");
    cr_assert_eq(links[0].first.second, 1);
    cr_assert_str_eq(links[0].second.first.c_str(), "out");
    cr_assert_eq(links[0].second.second, 1);
    delete file;
}
