/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:11:01 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:12:27 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

int	malloc_philo_and_forks(t_setting *set)
{
	if (pthread_mutex_init(&set->status, NULL))
		return (0);
	if (pthread_mutex_init(&set->meal_time, NULL))
		return (0);
	set->philo = malloc(sizeof(t_philo) * set->num_p);
	if (!set->philo)
		return (0);
	set->forks = malloc(sizeof(pthread_mutex_t) * set->num_p);
	if (!set->forks)
	{
		free(set->philo);
		return (0);
	}
	return (1);
}
