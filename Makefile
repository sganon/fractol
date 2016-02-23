# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sganon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 12:32:31 by sganon            #+#    #+#              #
#    Updated: 2016/02/23 14:17:16 by sganon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

SRC =	main.c \
		init.c \
		key_hook.c \

SRC_LIST =	$(addprefix srcs/, $(SRC))

O_FILES = $(SRC:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

LIBFT_FLAG = -L./libft -lft

MLX_FLAG = -lmlx -framework AppKit -framework OpenGL 

INC_FLAG = -I./includes

all : $(NAME)

$(NAME): 
		@make -C libft/ fclean
		@make -C libft/
		@echo "Libft compiled."
		@$(CC) $(CC_FLAGS) -c $(SRC_LIST) $(INC_FLAG)
		@echo "Objects compiled."
		@$(CC) $(CC_FLAGS) -o $(NAME) $(O_FILES) $(LIBFT_FLAG) $(MLX_FLAG) -lm $(INC_FLAG)
		@echo "Fractol compiled."

clean:
		@rm -f $(O_FILES)
		@make -C libft/ fclean
		@echo "Objects and libraries cleaned."

fclean : clean
		@rm -f $(NAME)
		@echo "Fractol cleaned."

re : fclean all
