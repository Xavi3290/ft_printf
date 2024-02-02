# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 12:45:30 by xroca-pe          #+#    #+#              #
#    Updated: 2024/01/30 16:57:10 by xroca-pe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = libftprintf.h Makefile
LIB = ar rcs

SRC = ft_string.c \
	  ft_numbers.c \
	  ft_printf.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re