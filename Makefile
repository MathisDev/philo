# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamottet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 23:27:48 by mamottet          #+#    #+#              #
#    Updated: 2023/12/14 23:27:49 by mamottet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc		= clang 
fl		= -Wall -Werror -Wextra 
link	= -pthread
exe 	= philo

src		= 	./src/aloc.c \
			./src/free.c \
			./src/init.c \
			./src/monitoring.c \
			./src/utils.c \
			./src/check.c \
			./src/main.c \
			./src/mutex.c \
			./src/ft_atoi_and_put.c \

all:
	$(cc) $(fl) $(link) $(src) -o $(exe)
clean:
	echo "Il n'y a rien a clean"
fclean:
	rm -fr $(exe)
re: fclean all

re: fclean all
