# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/17 19:27:32 by vnguyen           #+#    #+#              #
#    Updated: 2016/04/06 17:33:43 by vnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC_PATH = ./

OBJ_PATH =

INC_PATH = -I.

LIB_PATH = -L.

LIB_NAME =

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

SRC_NAME = main.c ft_rtv1.c ft_event.c ft_graph_utils.c ft_graph.c ft_collision.c ft_scenes.c

OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LDFLAGS = $(LIB_PATH) $(LIB_NAME)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
			    $(CC) $(LD_FLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit Libft/libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
			    $(CC) $(CFLAGS) $(INC_PATH)  -c $<

clean:
			    rm -f $(OBJ)

fclean: clean
			    rm -f $(NAME)

re: fclean all
