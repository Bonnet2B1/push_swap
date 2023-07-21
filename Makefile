# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 01:15:46 by edelarbr          #+#    #+#              #
#    Updated: 2023/07/21 20:13:52 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:=	push_swap
NAME_BONUS	:=	checker
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS		:=	srcs/instructions3.c \
				srcs/utils6.c \
				srcs/utils2.c \
				srcs/utils5.c \
				srcs/utils1.c \
				srcs/utils4.c \
				srcs/ft_split.c \
				srcs/instructions1.c \
				srcs/algorithm.c \
				srcs/push_swap.c \
				srcs/lilsort.c \
				srcs/instructions2.c \
				srcs/utils3.c \
				srcs/parser.c

SRCS_BONUS	:=	bonus/get_next_line/get_next_line_utils_bonus.c \
				bonus/get_next_line/get_next_line_bonus.c \
				bonus/srcs/instructions3_bonus.c \
				bonus/srcs/utils2_bonus.c \
				bonus/srcs/checker_bonus.c \
				bonus/srcs/utils1_bonus.c \
				bonus/srcs/ft_split_bonus.c \
				bonus/srcs/instructions1_bonus.c \
				bonus/srcs/reader_bonus.c \
				bonus/srcs/ft_strncmp_bonus.c \
				bonus/srcs/instructions2_bonus.c \
				bonus/srcs/utils3_bonus.c \
				bonus/srcs/parser_bonus.c

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
