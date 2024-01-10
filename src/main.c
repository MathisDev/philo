/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:53:53 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 22:55:28 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

int	main(int argc, char **argv)
{
	t_setting	set;

	if (argc != 5 && argc != 6)
	{
		printf("ERROR | [number of arguments]\n");
		return (0);
	}
	if (!parse_arg(--argc, ++argv, &set))
	{
		printf("ERROR | [input type]\n");
		return (0);
	}
	if (!init_philo_and_forks(&set))
	{
		printf("ERROR | [aloc]\n");
		return (0);
	}
	monitoring_wrapper(&set);
	join_threads(&set);
	free_philo_and_forks(&set);
}
