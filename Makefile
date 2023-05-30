# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 01:15:46 by edelarbr          #+#    #+#              #
#    Updated: 2023/05/29 22:17:38 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:=	push_swap
NAME_BONUS	:=	checker
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g -fsanitize=address
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS		:=	SRCS/instructions3.c \
				SRCS/utils6.c \
				SRCS/utils2.c \
				SRCS/utils5.c \
				SRCS/utils1.c \
				SRCS/utils4.c \
				SRCS/ft_split.c \
				SRCS/instructions1.c \
				SRCS/algorithm.c \
				SRCS/push_swap.c \
				SRCS/lilsort.c \
				SRCS/instructions2.c \
				SRCS/utils3.c \
				SRCS/parser.c

SRCS_BONUS	:=	BONUS/get_next_line/get_next_line_utils_bonus.c \
				BONUS/get_next_line/get_next_line_bonus.c \
				BONUS/SRCS/instructions3_bonus.c \
				BONUS/SRCS/utils2_bonus.c \
				BONUS/SRCS/checker_bonus.c \
				BONUS/SRCS/utils1_bonus.c \
				BONUS/SRCS/ft_split_bonus.c \
				BONUS/SRCS/instructions1_bonus.c \
				BONUS/SRCS/reader_bonus.c \
				BONUS/SRCS/ft_strncmp_bonus.c \
				BONUS/SRCS/instructions2_bonus.c \
				BONUS/SRCS/utils3_bonus.c \
				BONUS/SRCS/parser_bonus.c

OBJS		:=	$(SRCS:.c=.o)
OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

.c.o:
	@ $(CC) $(FLAGS) -c $< -o $(<:.c=.o)

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:=	\033[0m
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN 		:=	\033[1;36m
RM			:=	rm -f

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME) $(OBJS)
				@ echo "$(GREEN)$(NAME) created[0m ✔️"

$(NAME_BONUS):	$(OBJS_BONUS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME_BONUS) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)
				@ echo "$(GREEN)$(NAME_BONUS) created[0m ✔️"

clean:
				@ $(RM) $(OBJS) $(OBJS_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:			clean
				@ $(RM) $(NAME) $(RM) $(NAME_BONUS)
				@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:				fclean all

.PHONY:			all clean fclean re
