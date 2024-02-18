##
## EPITECH PROJECT, 2024
## MicroTekSpice
## File description:
## Makefile
##

## Config
NAME 	= 			nanotekspice

_SRC 	=			Main.cpp							\
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
					\
					Components/Elementary/And.cpp		\
					Components/Elementary/Not.cpp 		\
					Components/Elementary/Or.cpp 		\
					Components/Elementary/Xor.cpp		\
					\
					Components/Special/Input.cpp		\
					Components/Special/Output.cpp		\
					Components/Special/True.cpp			\
					Components/Special/False.cpp		\
					Components/Special/Clock.cpp		\
					\


SRCDIR 	= 			src/

SRC 	=			$(addprefix $(SRCDIR), $(_SRC))

OBJ 	= 			$(SRC:.cpp=.o)

INC 	= 			-I./include

FLAGS 	=			-W -Wall -Wextra -Werror -g3

## Colors
GREEN = @/bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW = @/bin/echo -e "\x1b[33m $1\x1b[0m"

## Rules
all: 		$(NAME)	clean

$(NAME):
		@g++ -o $(NAME) $(SRC) $(INC) $(LIBS) $(MODULES) $(FLAGS)
		@$(call GREEN,"Build Done ✅!")

clean:
		@rm -f $(OBJ)

fclean: 	clean
		@rm -f $(NAME)

re: 		fclean all
