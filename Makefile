# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 11:27:45 by jflorido          #+#    #+#              #
#    Updated: 2023/04/23 12:23:41 by arlo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

#ANSI Shadow
define HEADER


			██████╗ ██╗██████╗ ███████╗██╗  ██╗
			██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
			██████╔╝██║██████╔╝█████╗   ╚███╔╝
			██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗
			██║     ██║██║     ███████╗██╔╝ ██╗
			╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝

        ██████████████████████████████████████████████████████████████████████
        ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
        ██▒▒▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░░░██
        ██░░░░░░▒▒▒▒░░░░░░░░░░░░▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░░░██
        ██████████████████████████████████████████████████████████████████████
            ██████████████████████████████████████████████████████████████
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██
            ██░░░░░░▒▒▒▒▒▒░░░░░░░░▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░▒▒░░░░██
            ██░░░░▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒░░░░░░██

endef
export HEADER

# Folders
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

OBJF = obj
INC = inc

# Files
SRC_FILES = pipex path_utils pipex_utils
#SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Commands
CC 			= 	gcc
SANI 		= 	-g3 -fsanitize=address
CFLAGS 		= 	-Wall -Wextra -Werror
RM 			= 	rm -rf

LIBFT_a 	= 	libft/libft.a

#Colors:
DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;31m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# ====================================================================== #

all: $(NAME)

# Compiling all
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -I $(INC) $(LIBFT_a) -o $(NAME)
	@echo "$(GREEN)$$HEADER$(DEF_COLOR)"
	@echo "$(GREEN)Pipex compiled!$(DEF_COLOR)"

# Compiling individual
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(BLUE)Compiling $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

# Crear directorio temporal para los obj
$(OBJF):
	@mkdir -p $(OBJ_DIR)

# Cleanning files
clean:
	$(RM) $(OBJS)
	@make clean -C ./libft
	@echo "$(YELLOW)&(OBJS) --> Files removed.$(DEF_COLOR)"

#Cleanning files and executable
fclean: clean
	$(RM) $(NAME)
	@MAKE fclean -C ./libft
	@echo "$(RED)$(NAME) Executable files removed!$(DEF_COLOR)"

re: fclean all

normi:
	@norminette $(SRC_DIR) $(INC) $(LIBFT_DIR)

sani: fclean
	$(MAKE) CFLAGS='$(CFLAGS) $(SANI)' all

.PHONY: all clean fclean re