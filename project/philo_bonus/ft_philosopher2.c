/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/07 23:12:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_thread.h"
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"

static void	ft_philosopher_do_state(t_philosopher *philo)
{
	if (philo->status == PHILO_STATUS_INIT || \
			philo->status == PHILO_STATUS_THINK)
	{
		ft_philosopher_eat(philo);
		return ;
	}
	if (philo->status == PHILO_STATUS_EAT)
	{
		ft_philosopher_sleep(philo);
		return ;
	}
	if (philo->status == PHILO_STATUS_SLEEP)
	{
		ft_philosopher_think(philo);
		return ;
	}
}

void	*ft_philosopher_life(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (ft_mutex_bvalue_get(philo->end) == FALSE)
	{
		ft_philosopher_do_state(philo);
	}
	return (NULL);
}

void	ft_philosopher_sleep(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_SLEEP;
	timestamp = ft_timestamp_get();
	pthread_mutex_lock(&philo->end->mutex);
	if (philo->end->value == FALSE)
	{
		ft_thread_printf(philo, "is sleeping", timestamp - philo->start_time);
		pthread_mutex_unlock(&philo->end->mutex);
		ft_sleep(philo->rules.time_to_sleep);
		return ;
	}
	pthread_mutex_unlock(&philo->end->mutex);
}

void	ft_philosopher_think(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_THINK;
	timestamp = ft_timestamp_get();
	pthread_mutex_lock(&philo->end->mutex);
	if (philo->end->value == FALSE)
		ft_thread_printf(philo, "is thinking", timestamp - philo->start_time);
	pthread_mutex_unlock(&philo->end->mutex);
}
