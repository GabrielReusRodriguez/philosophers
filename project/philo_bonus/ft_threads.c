/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:21:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/12 14:06:27 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_timestamp.h"
#include "ft_log.h"

void	*ft_threads_check_philo_dead(void *args)
{
	t_timestamp		now;
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	philo->meals.timestamp = philo->start_time;
	while (TRUE)
	{
		now = ft_timestamp_get();
		if (now - philo->meals.timestamp >= philo->rules.time_to_die)
		{
			ft_log(philo, "died", now - philo->start_time);
			sem_wait(philo->sem_console);
			sem_post(philo->sem_dead);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}

void	*ft_threads_check_philo_meal(void *args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (TRUE)
	{
		if (philo->meals.num_meals >= philo->rules.number_eats)
		{
			sem_post(philo->sem_meal);
			break ;
		}
	}
	return (NULL);
}

void	*ft_threads_check_meals(void *args)
{
	size_t	i;
	t_table	*table;

	table = (t_table *)args;
	i = 0;
	while (i < table->philosophers_set.total)
	{
		sem_wait(table->sem_meal);
		i++;
	}
	return (NULL);
}

void	*ft_threads_check_deads(void *args)
{
	t_table	*table;

	table = (t_table *)args;
	sem_wait(table->sem_end);
	return (NULL);
}
