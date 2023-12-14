/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:59:20 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:27:33 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stddef.h>


typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			time_last_meal;
	int				c_meals;
	struct s_setting	*set;
}	t_philo;

typedef struct s_setting
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_time;
	bool			end;
	long			start_time;
	int				num_p;
	int				time_d;
	int				time_e;
	int				time_s;
	int				num_e;
}	t_setting;

int	parse_arg(int argc, char **argv, t_setting *set);
int	ft_atoi(const char *str, int *ret);
int	init_philo_and_forks(t_setting *set);
int	malloc_philo_and_forks(t_setting *set);
void	free_philo_and_forks(t_setting *set);
void	monitoring_wrapper(t_setting *set);
void	monitoring(t_setting *set);
long	find_ms(void);
long	elapsed(long start);
long	read_m_t(t_philo *philo);
void	set_m_t(t_philo *philo);

