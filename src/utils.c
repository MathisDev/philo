/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:02:28 by mamottet          #+#    #+#             */
/*   Updated: 2024/01/08 10:53:17 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

long	find_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long	elapsed(long start)
{
	return (find_ms() - start);
}

int	join_threads(t_setting *set)
{
	int	i;

	i = 0;
	while (i < set->num_p)
	{
		if (pthread_join(set->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (1);
}

void	print_lock(char *str, int id, t_setting *set, long ms)
{
	pthread_mutex_lock(&set->status);
	if (!set->end)
		printf("%ld %i %s\n", ms, id, str);
	pthread_mutex_unlock(&set->status);
}
