# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamottet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 23:27:48 by mamottet          #+#    #+#              #
#    Updated: 2023/12/15 13:54:07 by mamottet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc		= clang 
fl		= -Wall -Werror -Wextra 
link		= -pthread
link_check	= -g -fsanitize=thread -pthread

exe 		= philo
exe_check	= philo_check

src		= 	./src/aloc.c \
			./src/free.c \
			./src/init.c \
			./src/monitoring.c \
			./src/utils.c \
			./src/check.c \
			./src/main.c \
			./src/mutex.c \
			./src/ft_atoi_and_put.c \
			./src/philo.c

all:
	$(cc) $(fl) $(link) $(src) -o $(exe)
test:
	$(cc) $(fl) $(link_check) $(src) -o $(exe_check)
clean_mac:
	rm -fr philo_check.dSYM
	rm -fr $(exe) $(exe_check)
clean:
	echo "Il n'y a rien a clean"
fclean:
	rm -fr $(exe) $(exe_check)
re: fclean all

re: fclean all
