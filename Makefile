# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 19:07:32 by oubelhaj          #+#    #+#              #
#    Updated: 2023/02/16 03:08:40 by oubelhaj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  ./Mandatory/main.c \
		./Mandatory/check_input.c \
		./Mandatory/initialize_stack.c \
		./Mandatory/stack_utils.c \
		./Mandatory/utils.c \
		./Mandatory/rev_rotate_actions.c \
		./Mandatory/rotate_actions.c \
		./Mandatory/swap_actions.c \
		./Mandatory/push_actions.c \
		./Mandatory/mini_sort.c \
		./Mandatory/mini_sort_utils.c \
		./Mandatory/big_sort.c \
		./Mandatory/big_sort_utils.c \

B_SRCS = ./Bonus/bonus_main.c \
		./Bonus/check_input_bonus.c \
		./Bonus/initialize_stack_bonus.c \
		./Bonus/get_next_line.c \
		./Bonus/get_next_line_utils.c \
		./Bonus/push_actions_bonus.c \
		./Bonus/rev_rotate_actions_bonus.c \
		./Bonus/rotate_actions_bonus.c \
		./Bonus/stack_utils_bonus.c \
		./Bonus/utils_bonus.c \
		./Bonus/utils2_bonus.c \
		./Bonus/swap_actions_bonus.c \
		
OBJS = ${SRCS:.c=.o}

B_OBJS = ${B_SRCS:.c=.o}

CC = cc

BONUS = checker

CFLAGS = -Wall -Wextra -Werror -I ./Includes

.c.o	:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m- push_swap program compiled!\033[0m"

$(BONUS) : $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) -o $(BONUS)
	@echo "\033[1;32m- checker program compiled!\033[0m"

bonus : $(BONUS)

clean	:
	@rm -rf ./Mandatory/*.o
	@rm -rf ./Bonus/*.o
	@echo "\033[1;31m- Object files removed!\033[0m"

fclean	:	clean
	@rm -rf $(NAME) $(BONUS)
	@echo "\033[1;31m- push_swap/checker programs removed!\033[0m"

re : fclean all

.PHONY : all clean fclean re