/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:24:56 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:26:46 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

long	read_m_t(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->set->meal_time);
	last_meal_time = philo->time_last_meal;
	pthread_mutex_unlock(&philo->set->meal_time);
	return (last_meal_time);
}

void	set_m_t(t_philo *philo)
{
	pthread_mutex_lock(&philo->set->meal_time);
	philo->time_last_meal = find_ms();
	pthread_mutex_unlock(&philo->set->meal_time);
}
