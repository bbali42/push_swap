# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 01:38:21 by bbali             #+#    #+#              #
#    Updated: 2022/06/25 01:38:21 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror #-g
INC			=	-I ./inc/ -I ./libs/libft/inc
LIB			=	-L ./libs/libft -lft
LIB_DIR		=	libs/libft
DEP_INC		=	./inc/push_swap.h
SRC			=	main.c \
				check_args.c \
				args_parse.c \
				args_function.c \
				args_utils.c \
				stack_function.c \
				ops_function.c \
				radix_sort.c \
				sort_5.c \
				stack_utils.c \
				stack_check.c \
				swap.c \
				push.c \
				rot.c \
				revrot.c \
				utils.c


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
SRC_DIR		=	src/
OBJ_DIR		=	.objs/

# ~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~ #
all:
			@echo "$(_PURPLE_)Compiling ...$(_WHITE_)"
			@make install $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "$(_MEGAWHITE)push_swap ✔️$(_WHITE_)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEP_INC)
				@echo "$(_YELLOW_)$@$(_CYAN_)\r"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

# ~~~~~~~~~~~~~~ REQUIRED LIB ~~~~~~~~~~~~~~ #
install:
			@$(foreach dir, $(LIB_DIR), make -C $(dir);)
re-install:
			@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)
fclean-install:
			@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #		
clean:		
			@rm -rf $(OBJ_DIR)
			@echo "$(_RED_)[push_swap] object files deleted.$(_WHITE_)"

fclean:		fclean-install
			@make clean
			@rm -rf $(NAME)
			@echo "$(_RED_)[push_swap] binary file deleted.$(_WHITE_)"

re:			fclean all

# ~~~~~~~~~~~~~~~ COLOR ~~~~~~~~~~~~~~~~~~~ #
_GREEN_=\033[0;32m
_WHITE_=\033[0;37m
_MEGAWHITE=\033[1;37m
_YELLOW_=\033[1;33m
_PURPLE_=\033[0;35m
_CYAN_=\033[1;36m
_RED_=\033[0;31m

.PHONY:		all clean fclean re bonus install fclean-install re-install