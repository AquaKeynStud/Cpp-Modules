.PHONY : all bonus clean fclean re

NAME := a.out

# ╭━━━━━━━━━━━━══════════╕出 ❖ BASICS VARIABLES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

CXX				:=	c++

CXXFLAGS		:=	-Wall -Wextra -Werror -std=c++98

RM				:=	rm	-rf

MKDIR			:=	mkdir -p

SHOW_MSG_CLEAN	=	true

MAKEFLAGS		+=	--no-print-directory

# ╰━━━━━━━━━━━━━━━━════════════════╛出 ❖ 力╘════════════════━━━━━━━━━━━━━━━━╯ #

# ╭━━━━━━━━━━━━══════════╕出 ❖ FILE TREE ❖ 力╒═══════════━━━━━━━━━━━━╮ #

D_SRC		=	src/
D_INC		=	include/

D_OBJ		=	.objs/

vpath %.cpp $(D_SRC):$(D_SRC)Classes:$(D_SRC)Classes/Materias:$(CURDIR)
vpath %.hpp $(D_INC):$(D_INC)Interfaces:$(D_INC)Materias

# file lists
SRCS		=	main.cpp			\
				Ice.cpp				\
				Cure.cpp			\
				AMateria.cpp		\
				Character.cpp		\
				MateriaSource.cpp

INCS		=	$(addprefix $(D_INC), Character.hpp MateriaSource.hpp)									\
				$(addprefix $(D_INC)Materias/, AMateria.hpp Cure.hpp Ice.hpp)			\
				$(addprefix $(D_INC)Interfaces/, ICharacter.hpp IMateriaSource.hpp)

OBJS		=	$(addprefix $(D_OBJ), $(SRCS:.cpp=.o))

INC			=	-I$(D_INC) -I$(D_INC)Materias -I$(D_INC)Interfaces

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all:	$(NAME)

$(NAME):	$(OBJS) $(INCS) | Makefile $(D_OBJ)
	@$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\e[1;32m🎍 $(NAME) program created successfully ! 🎍\e[0m"

$(D_OBJ):
	@$(MKDIR) $(D_OBJ)

$(D_OBJ)%.o: %.cpp | Makefile $(D_OBJ)
	@echo "\e[1m🫧 Compiling $< 🫧\e[0m"
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(D_OBJ)
	@echo "\e[1;36m🫗 Deleted $(NAME) object files 🫗\e[0m"

fclean:
	@$(MAKE) -s SHOW_MSG_CLEAN=false clean
	@$(RM) $(NAME)
	@echo "\e[1;34m🧼 $(NAME) executable deleted ! 🧼\e[0m"

re:
	@$(MAKE) fclean
	@$(MAKE) all

valgrind:
	@$(MAKE)
	@clear
	@valgrind										\
		--leak-check=full								\
		--show-leak-kinds=all							\
		--track-origins=yes 							\
		--track-fds=yes									\
		./$(NAME)
