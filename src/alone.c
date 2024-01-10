/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:39:00 by mamottet          #+#    #+#             */
/*   Updated: 2024/01/08 11:48:13 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

int	is_alone(t_philo *philo)
{
	if (philo->set->num_p == 1)
	{
		if (philo->set->time_d > philo->set->time_e)
			return (1);
		return (2);
	}
	return (0);
}

void	alone(t_philo *philo)
{
	int	r_fork;

	r_fork = 0;
	print_lock("is thinking ", philo->id, philo->set,
		elapsed(philo->set->start_time));
	r_fork = determine_r_fork(philo);
	pthread_mutex_lock(&philo->set->forks[r_fork]);
	print_lock("has taken a fork", philo->id, philo->set,
		elapsed(philo->set->start_time));
}
