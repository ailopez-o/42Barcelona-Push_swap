# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 17:49:21 by aitoraudica       #+#    #+#              #
#    Updated: 2022/07/29 17:55:51 by aitoraudica      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Variables

NAME		:= push_swap

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
LIBFT_DIR		:= $(LIB)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
HEADER 			:= -I$(INC) -I$(LIBFT_DIR)


# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	push_swap lst_utils print rab rrab sab_pab

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	$(NAME)
			
-include 	${DEPS}
$(NAME):	$(LIBFT) $(OBJ)
			make -sC $(LIBFT_DIR)			
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) -o $(NAME)		
			@echo "👉 $(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) -o $(NAME) $(DEF_COLOR)"
			@echo "$(GREEN)✨ push_swap compiled!$(DEF_COLOR)"

			

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"	
		
clean:
			@make clean -sC $(LIBFT_DIR)
			@echo "$(CYAN)Libft object and dependency files cleaned.$(DEF_COLOR)"
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"			
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

