# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamottet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 23:27:48 by mamottet          #+#    #+#              #
#    Updated: 2024/01/08 11:45:38 by mamottet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc		= clang 
fl		= -Wall -Werror -Wextra 
link		= -pthread
exe 		= philo
src		= 	./src/aloc.c \
			./src/free.c \
			./src/init.c \
			./src/monitoring.c \
			./src/utils.c \
			./src/check.c \
			./src/main.c \
			./src/mutex.c \
			./src/ft_atoi_and_put.c \
			./src/philo.c \
			./src/alone.c
srco = $(src:.c=.o)

all: $(exe)

$(exe): $(srco)
	$(cc) $(fl) $(link) $(srco) -o $(exe)
clean:
	rm -fr $(srco)
fclean: clean
	rm -fr $(exe)

re: fclean all

.PHONY: all clean fclean re
