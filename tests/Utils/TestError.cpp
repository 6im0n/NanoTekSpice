/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestError
*/

#include "Utils/Error.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Error, testThrowError)
{
    cr_assert_throw(throw nts::Error("Test"), nts::Error);
}

Test(Error, testMessageError)
{
    cr_redirect_stderr();
    try {
        throw nts::Error("Test");
    } catch (nts::Error &e) {
        cr_assert_str_eq(e.what(), "Test");
    }
}

Test(Error, testPrintingError)
{
    cr_redirect_stderr();
    try {
        throw nts::Error("Test");
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    std::fflush(stderr);
    cr_assert_stderr_eq_str("Test\n");
}

Test(ShellError, testThrowShellError)
{
    cr_assert_throw(throw nts::ShellError("Test"), nts::ShellError);
}

Test(ShellError, testMessageShellError)
{
    cr_redirect_stderr();
    try {
        throw nts::ShellError("Test");
    } catch (nts::ShellError &e) {
        cr_assert_str_eq(e.what(), "Test");
    }
}

Test(ShellError, testPrintingShellError)
{
    cr_redirect_stderr();
    try {
        throw nts::ShellError("Test");
    } catch (nts::ShellError &e) {
        std::cerr << e.what() << std::endl;
    }
    std::fflush(stderr);
    cr_assert_stderr_eq_str("Test\n");
}