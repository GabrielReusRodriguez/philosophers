/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:45:05 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/09 08:46:32 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_philosopher.h"

/*
	We print at threads with this function. 
	First we block the log (only one thread can write)
	Then we check that the simulation is NOT over.
*/
void	ft_log(t_philosopher *philo, const char *str, \
			t_timestamp time)
{
	pthread_mutex_lock(&philo->log->mutex);
	printf("%llu", time);
	printf(" %d ", philo->number);
	printf("%s\n", str);
	pthread_mutex_unlock(&philo->log->mutex);
}
