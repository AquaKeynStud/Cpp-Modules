.PHONY : all bonus clean fclean re

NAME := refs

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CXX				:=	c++

CFLAGS			:=	-Wall -Wextra -Werror -std=c++98

RM				:=	rm	-rf

MKDIR			:=	mkdir -p

SHOW_MSG_CLEAN	=	true

MAKEFLAGS		+=	--no-print-directory

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

# file lists
LST_SRC		=	main.cpp

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all:	$(NAME)

$(NAME):	$(LST_SRC) | Makefile
	@$(CXX) $(CFLAGS) $(LST_SRC) -o $(NAME)
	@echo "\e[1;32m🎍 $(NAME) program created successfully ! 🎍\e[0m"

clean:
	@echo "\e[1;36m🫗 No object file found for $(NAME) 🫗\e[0m"

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME)
	@echo "\e[1;34m🧼 $(NAME) executable deleted ! 🧼\e[0m"

re:
	@$(MAKE) fclean
	@$(MAKE) all
