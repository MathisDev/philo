/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:16:35 by mamottet          #+#    #+#             */
/*   Updated: 2024/01/08 11:15:13 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

void	monitoring_wrapper(t_setting *set)
{
	while (!check_end(set))
	{
		monitoring(set);
		usleep(1);
	}
}

void	monitoring(t_setting *set)
{
	int		i;
	long	diff_meal;

	i = 0;
	while (i < set->num_p)
	{
		diff_meal = find_ms() - read_m_t(&set->philo[i]);
		if (set->time_d < diff_meal)
		{
			change_end(set);
			pthread_mutex_lock(&set->philo[i].meal_mutex);
			if (set->philo[i].c_meals != 0)
				printf("%ld %d died \n",
					elapsed(set->start_time) - 1, set->philo[i].id);
			pthread_mutex_unlock(&set->philo[i].meal_mutex);
			return ;
		}
		i++;
	}
}
