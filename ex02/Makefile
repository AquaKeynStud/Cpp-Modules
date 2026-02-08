.PHONY : all clean fclean re

NAME := moreForms.cpp5

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

vpath %.cpp $(D_SRC):$(CURDIR)

# file lists
SRCS		=	main.cpp AForm.cpp Bureaucrat.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp
INCS		=	$(addprefix $(D_INC), Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp)
OBJS		=	$(addprefix $(D_OBJ), $(SRCS:.cpp=.o))

INC			=	-I$(D_INC)

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all:	$(NAME)
	@clear
	@./$(NAME)

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
	@$(RM) $(NAME) *_shrubbery
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