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

PUSH_SWAP_DIR := pushswap/
CHECKER_DIR := checker/


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



all:	
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)push_swap push_swap

			
clean:
		@make clean -sC $(PUSH_SWAP_DIR)

fclean:		
		@make fclean -sC $(PUSH_SWAP_DIR)


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap/checker!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

