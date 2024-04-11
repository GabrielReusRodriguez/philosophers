/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:21:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 21:37:44 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_timestamp.h"

/*
int ft_threads_check_philo_dead(t_philosopher *philo)
{
	t_timestamp now;
	
	while(TRUE)
	{
		now = ft_timestamp_get();
		if (now - philo->meals.timestamp >= philo->rules.time_to_die)
		{
			sem_post(philo->sem_end);
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}
*/

void    *ft_threads_check_philo_dead(void *args)
{
	t_timestamp     now;
	t_philosopher   *philo;

	philo  = (t_philosopher *)args;
	philo->meals.timestamp = philo->start_time;
	while(TRUE)
	{
		now = ft_timestamp_get();
		if (now - philo->meals.timestamp >= philo->rules.time_to_die)
		{
			sem_post(philo->sem_dead);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}

void    *ft_threads_check_philo_meal(void * args)
{
	t_philosopher *philo;

	philo = (t_philosopher *)args;
	while(TRUE)
	{
		if (philo->meals.num_meals >= philo->rules.number_eats)
		{
			sem_post(philo->sem_meal);
			break;
		}
	}
	return (NULL);
}
/*
int ft_threads_check_philo_meal(t_philosopher *philo)
{
	while(TRUE)
	{
		if (philo->meals.num_meals >= philo->rules.number_eats)
		{
			sem_post(philo->sem_meal);
			break;
		}
	}
	return (0);
}
*/

void *	ft_threads_check_meals(void * args)
{
	size_t  i;
	t_table *table;

	table = (t_table *)args;
	i = 0;
	while (i < table->philosophers_set.total)
	{
		sem_wait(table->sem_meal);
		i++;
	}
	//call to kill  pids function
	return (NULL);
}

void	*ft_threads_check_deads(void *args)
{
	t_table *table;

	table = (t_table *)args;
	sem_wait(table->sem_end);
	//call to kill  pids function
	return (NULL);
}