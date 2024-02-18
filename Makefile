##
## EPITECH PROJECT, 2024
## MicroTekSpice
## File description:
## Makefile
##

## Config
NAME 	= 			nanotekspice

_SRC 	=			Main.cpp							\
					Acomponent.cpp						\
          			NanoTekSpice.cpp					\
					Parsing/CircuitFile.cpp				\
					Utils/Utils.cpp						\
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
					AChipset.cpp						\
					\
					Components/Gates/4081.cpp			\
					Components/Gates/4071.cpp			\
					Components/Gates/4069.cpp			\
					Components/Gates/4030.cpp			\
					Components/Gates/4011.cpp			\
					Components/Gates/4001.cpp			\



SRCDIR 	= 			src/

SRC 	=			$(addprefix $(SRCDIR), $(_SRC))

OBJ 	= 			$(SRC:.cpp=.o)

INC 	= 			-I./include

FLAGS 	=			-W -Wall -Wextra -Werror -g3

LD 		= 			g++

## Colors
GREEN = /bin/echo -e "\x1b[32m $1\x1b[0m"
YELLOW = /bin/echo -e "\x1b[33m $1\x1b[0m"

## Rules
all: 		$(NAME)

$(NAME):  $(OBJ)
		@$(LD) -o $(NAME) $(OBJ)
		@$(call GREEN,"Build Done ✅!")

%.o: 	%.cpp
		@$(CXX) $(FLAGS) $(INC) -c -o $@ $< && \
		$(call YELLOW,"✅ $<") || \
		$(call YELLOW,"❌ $<")
clean:
		@rm -f $(OBJ)

fclean: 	clean
		@rm -f $(NAME)

re: 		fclean all
