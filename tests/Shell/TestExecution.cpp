/*
** EPITECH PROJECT, 2024
** MicroTekSpice
** File description:
** TestExecution
*/

#include "Shell/Execution.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Execution, testBasicExecution)
{
    nts::CircuitFile file("TestFile/NtsSingle/and.nts");
    nts::NanoTekSpice nano(file);
    nts::Execution *exec = new nts::Execution(nano);

    cr_assert_not_null(exec);
}
