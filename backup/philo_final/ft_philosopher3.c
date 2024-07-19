/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:58:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/04 23:48:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosopher.h"
#include "ft_thread.h"
#include "ft_sleep.h"

/* Philosopher takes A fork.*/
static int	ft_philosopher_pickup_forks(t_philosopher *philo)
{
	t_timestamp	timestamp;

	ft_fork_pickup(philo->l_fork, philo->number, 1);
	timestamp = ft_timestamp_get();
	ft_thread_printf(philo, "has taken a fork", timestamp - philo->start_time);
	if (philo->total == 1)
	{
		ft_sleep(philo->rules.time_to_die);
		ft_fork_drop(philo->l_fork);
		return (1);
	}
	ft_fork_pickup(philo->r_fork, philo->number, 2);
	timestamp = ft_timestamp_get();
	ft_thread_printf(philo, "has taken a fork", \
		timestamp - philo->start_time);
	return (0);
}

/* Philosopher eats.*/
void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	if (ft_mutex_bvalue_get(philo->end) == FALSE)
	{
		philo->status = PHILO_STATUS_EAT;
		if (ft_philosopher_pickup_forks(philo) == 1)
			return ;
		if (ft_mutex_bvalue_get(philo->end) == FALSE)
		{
			timestamp = ft_timestamp_get();
			ft_mutex_meal_update(&philo->meals, timestamp);
			ft_thread_printf(philo, "is eating", timestamp - philo->start_time);
		}
		ft_sleep(philo->rules.time_to_eat);
	}
}
