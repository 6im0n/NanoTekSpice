##
## EPITECH PROJECT, 2024
## MicroTekSpice
## File description:
## Makefile
##

## Config
NAME 		= 			nanotekspice

_SRC 		=			Main.cpp							\
						NanoTekSpice.cpp					\
						\
						Shell/Execution.cpp					\
						\
						Parsing/CircuitFile.cpp				\
						\
						Utils/Utils.cpp						\
						Utils/Error.cpp						\
						Utils/Tristate.cpp 					\
						\
						Components/AComponent.cpp			\
						Components/AChipset.cpp				\
						\
						Components/Elementary/And.cpp		\
						Components/Elementary/Not.cpp 		\
						Components/Elementary/Nand.cpp		\
						Components/Elementary/Or.cpp 		\
						Components/Elementary/Nor.cpp		\
						Components/Elementary/Xor.cpp		\
						\
						Components/Special/Input.cpp		\
						Components/Special/Output.cpp		\
						Components/Special/True.cpp			\
						Components/Special/False.cpp		\
						Components/Special/Clock.cpp		\
						\
						Components/Gates/4081.cpp			\
						Components/Gates/4071.cpp			\
						Components/Gates/4069.cpp			\
						Components/Gates/4030.cpp			\
						Components/Gates/4011.cpp			\
						Components/Gates/4001.cpp			\
						\
						Components/Extra/Duplicate.cpp		\
						Components/Extra/FullAdder.cpp		\
						Components/Extra/DFlipFlop.cpp		\
            			Components/Extra/Logger.cpp		    \
						\
						Components/Advanced/4008.cpp		\
						Components/Advanced/4013.cpp		\
						Components/Advanced/4514.cpp		\
						Components/Advanced/4017.cpp 		\
						Components/Advanced/4094.cpp		\
						Components/Advanced/4512.cpp		\
						Components/Advanced/4040.cpp		\



SRCDIR 		= 			src/

SRC 		=			$(addprefix $(SRCDIR), $(_SRC))

OBJ 		= 			$(SRC:.cpp=.o)

_OBJ 		= 			$(filter-out $(SRCDIR)Main.o, $(OBJ))

INC 		= 			-I./include

FLAGS 		=			-W -Wall -Wextra -Werror -g3 --coverage

TESTFLAGS 	=			-lcriterion --coverage

GCOVRFLAGS 	= 			--exclude tests/

CXX 		= 			g++

## Tests
_TESTS_SRC	=			TestNanoTekSpice.cpp					\
						\
						Parsing/TestCircuitFile.cpp				\
						\
						Shell/TestExecution.cpp					\
						\
						Utils/TestError.cpp						\
						Utils/TestTristate.cpp 					\
						\
						Components/TestSpecialComponents.cpp	\
						Components/TestElementaryComponents.cpp	\
						Components/TestExtraComponents.cpp		\
						Components/TestGatesComponents.cpp		\
						Components/TestAdvancedComponents.cpp	\



TESTSDIR 	=			tests/

TESTS_SRC	=			$(addprefix $(TESTSDIR), $(_TESTS_SRC))

TESTS_OBJ	=			$(TESTS_SRC:.cpp=.o)

## Colors
GREEN = /bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW = /bin/echo -e "\x1b[33m $1\x1b[0m"

## Rules
all: 		$(NAME)

$(NAME): 	$(OBJ)
		@$(CXX) $(FLAGS) -o $(NAME) $(OBJ)
		@$(call GREEN,"Build Done ✅!")

%.o: 		%.cpp
		@$(CXX) $(FLAGS) $(INC) -c -o $@ $< && \
		$(call YELLOW,"✅ $<") || \
		$(call YELLOW,"❌ $<")

clean:
		@rm -f $(OBJ)
		@rm -f $(TESTS_OBJ)
		@find ./ -name "*.gcno" -delete
		@find ./ -name "*.gcda" -delete

fclean: 	clean
		@rm -f $(NAME)
		@rm -f unit_tests

re: 		fclean all

tests_run: 	clean $(TESTS_OBJ) $(_OBJ)
		@$(CXX) -o unit_tests $(TESTS_OBJ) $(_OBJ) $(INC) $(TESTFLAGS)
		@./unit_tests
		@gcovr --exclude tests/

web_coverage:	tests_run
		@mkdir -p WebCoverage
		@gcovr $(GCOVRFLAGS) --html --html-details -o WebCoverage/coverage.html
