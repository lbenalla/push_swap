# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labenall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:04:26 by labenall          #+#    #+#              #
#    Updated: 2022/03/15 18:41:47 by labenall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c

OBJSFD  = temporary

OBJ = $(addprefix $(OBJSFD)/,$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS)  -c $< -o $@

$(NAME1): $(OBJS1)
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJSFD)

re: fclean all

.PHONY: all clean fclean re
