/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:58:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 08:47:52 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosopher.h"
#include "ft_thread.h"
#include "ft_sleep.h"
#include "ft_log.h"

/* Philosopher takes A fork.*/
static int	ft_philosopher_pickup_forks(t_philosopher *philo)
{
	t_timestamp	timestamp;

	ft_fork_pickup(philo->l_fork, philo->number, 1);
	timestamp = ft_timestamp_get();
	pthread_mutex_lock(&philo->end->mutex);
	if (philo->end->value == FALSE)
		ft_log(philo, "has taken a fork", \
			timestamp - philo->start_time);
	pthread_mutex_unlock(&philo->end->mutex);
	if (philo->total == 1)
	{
		ft_sleep(philo->rules.time_to_die);
		ft_fork_drop(philo->l_fork);
		return (1);
	}
	ft_fork_pickup(philo->r_fork, philo->number, 2);
	timestamp = ft_timestamp_get();
	pthread_mutex_lock(&philo->end->mutex);
	if (philo->end->value == FALSE)
		ft_log(philo, "has taken a fork", \
			timestamp - philo->start_time);
	pthread_mutex_unlock(&philo->end->mutex);
	return (0);
}

/* Philosopher eats.*/
void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	pthread_mutex_lock(&philo->end->mutex);
	if (philo->end->value == FALSE)
	{
		pthread_mutex_unlock(&philo->end->mutex);
		philo->status = PHILO_STATUS_EAT;
		if (ft_philosopher_pickup_forks(philo) == 1)
			return ;
		timestamp = ft_timestamp_get();
		pthread_mutex_lock(&philo->end->mutex);
		if (philo->end->value == FALSE)
		{
			pthread_mutex_unlock(&philo->end->mutex);
			ft_mutex_meal_update(&philo->meals, timestamp);
			pthread_mutex_lock(&philo->end->mutex);
			ft_log(philo, "is eating", timestamp - philo->start_time);
			pthread_mutex_unlock(&philo->end->mutex);
			ft_sleep(philo->rules.time_to_eat);
			ft_fork_drop(philo->r_fork);
			ft_fork_drop(philo->l_fork);
		}
		else
			pthread_mutex_unlock(&philo->end->mutex);
	}
}
