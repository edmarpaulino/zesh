# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin </var/spool/mail/edpaulin>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 15:18:39 by edpaulin          #+#    #+#              #
#    Updated: 2021/12/30 10:15:12 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	zesh

SRC 			=	src
SRC_FILES 		=	main.c \
					get_input.c \
					prompt.c \
					source.c

OBJ				=	obj
OBJ_FILES		=	$(addprefix $(OBJ)/, $(SRC_FILES:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
LIB				=	-lreadline

INC				=	-I inc -I libft/inc

LIBFT			=	libft/libft.a

MKD				=	mkdir -p $(@D)
RM				=	rm -rf

.DEFAULT_GOAL	=	all

all: $(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	$(MKD)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ_FILES)
	make all -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) $(LIBFT) -o $(NAME) $(LIB)

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
