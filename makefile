# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 16:16:18 by kmira             #+#    #+#              #
#    Updated: 2019/05/20 14:33:24 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = fillit
LIBRARY = libft/libft.a

FILES = \
			encoding \
			input \
			main \
			output \
			piece_sanitization \
			solver \
			solving_utils

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJS)
	@echo "\033[32m""Making your fillit executable"
	@gcc -o fillit $(OBJS) $(LIBRARY)
	@echo "\033[32m""Done!"

$(LIBRARY):
	make -C libft/
	make clean -C libft/

$(OBJS):
	gcc $(FLAGS) -c $(SRCS)

clean:
	@echo "Cleaning your .o files"
	@rm -f libft.a
	@rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: clean all
