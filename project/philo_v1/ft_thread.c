/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:28 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 00:25:25 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_sleep.h"

#include <stdio.h>
//https://man7.org/linux/man-pages/man3/pthread_create.3.html
//https://github.com/DeRuina/philosophers/blob/main/src/threads.c

int	ft_thread_sleep(int milliseconds)
{
	//return (usleep(milliseconds * 1000)); 
	return (usleep(milliseconds)); 
}

//int ft_thread_create_threads(t_philosopher_set *philo)
int ft_thread_create_threads(t_table *table)
{
	size_t		i;
	pthread_t	thread_id;

	table->start_time = ft_timestamp_get();
	i = 0;
//	printf("Create thread num: %lu\n", tablphilo->total);
	while (i < table->philosophers_set.total)
	{
		table->philosophers_set.philosophers[i].start_time = table->start_time;
		table->philosophers_set.philosophers[i].meals.timestamp = table->start_time;
		table->philosophers_set.philosophers[i].end = &table->end;
		table->philosophers_set.philosophers[i].log = &table->log;
		table->philosophers_set.philosophers[i].start = &table->start;
		table->philosophers_set.philosophers[i].rules = table->rules;
		if (table->philosophers_set.philosophers[i].number % 2 == 0)
			ft_sleep(1);
		pthread_create(&thread_id, NULL, ft_philosopher_life, \
				table->philosophers_set.philosophers + i);
		table->philosophers_set.philosophers[i].thread = thread_id;
		i++;
	}

	return (0);
}

int	ft_thread_join_threads(t_philosopher_set *philo)
{
	size_t	i;

	i = 0;
	while(i < philo->total)
	{
		pthread_join(philo->philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}

void	ft_thread_printf(t_philosopher *philo, const char *str, t_timestamp time)
{	
	//pthread_mutex_lock(&philo->rules->log);
	//if(philo->end == FALSE)
	if(ft_mutex_bvalue_get(philo->end) == FALSE)
	{
		pthread_mutex_lock(&philo->log->mutex);
		printf("%llu", time);
		printf(" %d ", philo->number);
		printf("%s\n", str);
		pthread_mutex_unlock(&philo->log->mutex);
	}
	//pthread_mutex_unlock(&philo->rules->log);
}