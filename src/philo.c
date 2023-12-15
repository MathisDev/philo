/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:37:06 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/15 12:37:20 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include.h"

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
	print_lock("has picked up a fork", philo->id, philo->set,
		elapsed(philo->set->start_time));
	pthread_mutex_lock(&philo->set->forks[philo->id]);
	print_lock("has picked up a fork", philo->id, philo->set,
		elapsed(philo->set->start_time));
	set_m_t(philo);
	philo->c_meals--;
	print_lock("is eating ", philo->id, philo->set,
		elapsed(philo->set->start_time));
	ft_sleep(philo->set->time_e);
	pthread_mutex_unlock(&philo->set->forks[r_fork]);
	pthread_mutex_unlock(&philo->set->forks[philo->id]);
	return (1);
}

void	*life(void *tmp)
{
	t_philo			*philo;

	philo = tmp;
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
	return (NULL);
}