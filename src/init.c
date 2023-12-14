/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:56:26 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:09:57 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include.h"

int	parse_arg(int argc, char **argv, t_setting *set)
{
	set->num_p = 0;
	set->num_e = 0;
	set->time_d = 0;
	set->time_e = 0;
	set->time_s = 0;
	set->start_time = find_ms();
	set->end = false;
	if (ft_atoi(argv[0], &set->num_p)
		|| ft_atoi(argv[1], &set->time_d)
		|| ft_atoi(argv[2], &set->time_e)
		|| ft_atoi(argv[3], &set->time_s))
		return (0);
	if (set->num_p < 1)
		return (0);
	if (argc == 5)
	{
		if (ft_atoi(argv[4], &set->num_e))
			return (0);
	}
	else
		set->num_e = -1;
	return (1);
}

int	init_philo_and_forks(t_setting *set)
{
	int	i;

	if (!malloc_philo_and_forks(set))
		return (0);
	i = 0;
	while (i < set->num_p)
	{
		if (pthread_mutex_init(&set->forks[i++], NULL))
		{
			free_philo_and_forks(set);
			return (0);
		}
	}
	i = 0;
	while (i < set->num_p)
	{
		if (create_philo(set, i))
		{
			free_philo_and_forks(set);
			return (0);
		}
		i++;
	}
	return (1);
}
