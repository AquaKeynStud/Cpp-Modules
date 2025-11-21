.PHONY : all bonus clean fclean re

NAME := unnecessary_violence

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

# file lists
SRCS		=	$(wildcard $(D_SRC)*.cpp)
INCS		=	$(wildcard $(D_INC)*.hpp)
OBJS		=	$(patsubst $(D_SRC)%.cpp,$(D_OBJ)%.o,$(SRCS))

INC			=	-I$(D_INC)

# ╭━━━━━━━━━━━━══════════╕出 ❖ RULES ❖ 力╒═══════════━━━━━━━━━━━━╮ #

all:	$(NAME)

$(NAME):	$(OBJS) | Makefile $(D_OBJ)
	@$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\e[1;32m🎍 $(NAME) program created successfully ! 🎍\e[0m"

$(D_OBJ):
	@$(MKDIR) $(D_OBJ)

$(D_OBJ)%.o: $(D_SRC)%.cpp | Makefile $(D_OBJ)
	@echo "Compiling $<"
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
