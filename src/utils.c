/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:02:28 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:23:00 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include.h"

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
