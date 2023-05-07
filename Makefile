# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 01:15:46 by edelarbr          #+#    #+#              #
#    Updated: 2023/05/07 10:18:25 by edelarbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:=	push_swap
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror -g
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
				SRCS/parser.c \

SRCS_BONUS	:=	BONUS/get_next_line/get_next_line_utils.c \
				BONUS/get_next_line/get_next_line.c \
				BONUS/SRCS/instructions3.c \
				BONUS/SRCS/utils2.c \
				BONUS/SRCS/checker.c \
				BONUS/SRCS/utils1.c \
				BONUS/SRCS/ft_split.c \
				BONUS/SRCS/instructions1.c \
				BONUS/SRCS/reader.c \
				BONUS/SRCS/ft_strncmp.c \
				BONUS/SRCS/instructions2.c \
				BONUS/SRCS/utils3.c \
				BONUS/SRCS/parser.c \

OBJS		:=	$(SRCS:.c=.o)
OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM			:= rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		${OBJS} ${OBJS_BONUS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS_BONUS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


