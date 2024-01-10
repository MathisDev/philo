/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:37:06 by mamottet          #+#    #+#             */
/*   Updated: 2024/01/08 11:49:35 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_sleep(int time)
{
	long	start;
	long	elapsed;

	start = find_ms();
	elapsed = 0;
	while (elapsed < time)
	{
		usleep(time * 1000);
		elapsed = find_ms() - start;
	}
}

int	determine_r_fork(t_philo *philo)
{
	if (philo->id == 0)
		return (philo->set->num_p - 1);
	else
		return (philo->id - 1);
}

int	ft_eat(t_philo *philo)
{
	int	r_fork;

	r_fork = determine_r_fork(philo);
	pthread_mutex_lock(&philo->set->forks[r_fork]);
	print_lock("has taken a fork", philo->id, philo->set,
		elapsed(philo->set->start_time));
	pthread_mutex_lock(&philo->set->forks[philo->id]);
	print_lock("has taken a fork", philo->id, philo->set,
		elapsed(philo->set->start_time));
	set_m_t(philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->c_meals--;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_lock("is eating ", philo->id, philo->set,
		elapsed(philo->set->start_time));
	ft_sleep(philo->set->time_e);
	pthread_mutex_unlock(&philo->set->forks[philo->id]);
	pthread_mutex_unlock(&philo->set->forks[r_fork]);
	return (1);
}

void	*life(void *tmp)
{
	t_philo		*philo;
	int			philo_status;

	philo = tmp;
	philo_status = 0;
	philo_status = is_alone(philo);
	if (philo_status == 1)
		alone(philo);
	else if (philo_status == 2)
		return (NULL);
	else
	{
		if (philo->id % 2 == 0)
			usleep(philo->set->time_e * 1000);
		while (!check_end(philo->set) && philo->c_meals != 0)
		{
			print_lock("is thinking ", philo->id, philo->set,
				elapsed(philo->set->start_time));
			ft_eat(philo);
			print_lock("is sleeping ", philo->id, philo->set,
				elapsed(philo->set->start_time));
			ft_sleep(philo->set->time_s);
		}
	}
	return (NULL);
}
