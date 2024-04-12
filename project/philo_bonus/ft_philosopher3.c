/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:58:06 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/12 13:10:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "ft_philosopher.h"
#include "ft_sleep.h"
#include "ft_log.h"

/* Philosopher takes fork.*/
static int	ft_philosopher_pickup_forks(t_philosopher *philo)
{
	t_timestamp	timestamp;

	sem_wait(philo->sem_forks);
	philo->l_fork = TRUE;
	timestamp = ft_timestamp_get();
	ft_log(philo, "has taken a fork", timestamp - philo->start_time);
	if (philo->total == 1)
	{
		ft_sleep(philo->rules.time_to_die);
		sem_post(philo->sem_forks);
		return (1);
	}
	sem_wait(philo->sem_forks);
	philo->r_fork = TRUE;
	timestamp = ft_timestamp_get();
	ft_log(philo, "has taken a fork", timestamp - philo->start_time);
	return (0);
}

/* Philosopher eats.*/
void	ft_philosopher_eat(t_philosopher *philo)
{
	t_timestamp	timestamp;

	philo->status = PHILO_STATUS_EAT;
	if (ft_philosopher_pickup_forks(philo) == 1)
		return ;
	timestamp = ft_timestamp_get();
	philo->meals.timestamp = timestamp;
	philo->meals.num_meals++;
	ft_log(philo, "is eating", timestamp - philo->start_time);
	ft_sleep(philo->rules.time_to_eat);
	philo->l_fork = FALSE;
	sem_post(philo->sem_forks);
	philo->r_fork = FALSE;
	sem_post(philo->sem_forks);
}
