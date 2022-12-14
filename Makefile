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

PUSH_SWAP_DIR := srcs/mandatory/
CHECKER_DIR := srcs/checker/


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
	@echo " "
	@echo "$(BLUE)Launchig push_swap Makefile...$(DEF_COLOR)"
	@rm -f push_swap
	@make -C $(PUSH_SWAP_DIR)
	@cp $(PUSH_SWAP_DIR)push_swap push_swap
	@echo "$(BLUE)Launchig checker Makefile...$(DEF_COLOR)"	
	@rm -f my_checker
	@make -C $(CHECKER_DIR)
	@cp $(CHECKER_DIR)my_checker my_checker

			
clean:
		rm -f push_swap
		@make clean -sC $(PUSH_SWAP_DIR)
		@make clean -sC $(CHECKER_DIR)		

fclean:		
		rm -f push_swap
		@make fclean -sC $(PUSH_SWAP_DIR)
		@make fclean -sC $(CHECKER_DIR)


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap/checker!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

