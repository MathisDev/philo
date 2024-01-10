/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamottet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:19:07 by mamottet          #+#    #+#             */
/*   Updated: 2023/12/14 23:20:16 by mamottet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include.h"

int	check_end(t_setting *set)
{
	int	status;

	pthread_mutex_lock(&set->status);
	if (set->end)
		status = 1;
	else
		status = 0;
	pthread_mutex_unlock(&set->status);
	return (status);
}

void	change_end(t_setting *set)
{
	pthread_mutex_lock(&set->status);
	set->end = true;
	pthread_mutex_unlock(&set->status);
}
