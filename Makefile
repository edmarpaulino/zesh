# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 15:18:39 by edpaulin          #+#    #+#              #
#    Updated: 2022/01/05 14:14:31 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	zesh

TEST			=	test
TEST_FILES		=	test_scanner.c
TEST_PATH		=	$(addprefix $(TEST)/, $(TEST_FILES))

SCAN			=	scanner
SCAN_FILES		=	scanner.c \
					scanner_buffer.c
SCAN_PATH		=	$(addprefix $(SCAN)/, $(SCAN_FILES))

SRC 			=	./src
SRC_FILES 		=	main.c \
					get_input.c \
					prompt.c \
					source.c \
					$(TEST_PATH) \
					$(SCAN_PATH)

OBJ				=	./obj
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
