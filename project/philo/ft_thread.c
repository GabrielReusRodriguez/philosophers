/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 08:44:53 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_sleep.h"
#include <stdio.h>

/*
	Sleep 
*/
int	ft_thread_sleep(int microseconds)
{
	return (usleep(microseconds));
}

int	ft_thread_create_threads(t_table *table)
{
	size_t			i;
	pthread_t		thread_id;
	t_philosopher	*philo;

	table->start_time = ft_timestamp_get();
	i = 0;
	while (i < table->philosophers_set.total)
	{
		philo = table->philosophers_set.philosophers + i;
		philo->start_time = table->start_time;
		philo->meals.timestamp = table->start_time;
		philo->end = &table->end;
		philo->log = &table->log;
		philo->start = &table->start;
		philo->rules = table->rules;
		if (philo->number % 2 == 0)
			ft_sleep(1);
		pthread_create(&thread_id, NULL, ft_philosopher_life, philo);
		philo->thread = thread_id;
		i++;
	}
	return (0);
}

/*
	We do join of all threads to free resources.
*/
int	ft_thread_join_threads(t_philosopher_set *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->total)
	{
		pthread_join(philo->philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}
