/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 00:34:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/21 00:48:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "simulation.h"
#include "philosopher.h"
#include "utils.h"
#include "timestamp.h"
#include "printer.h"
#include "threads.h"

static bool philo_take_fork(t_philosopher *philo, size_t num_fork)
{
	t_milisecs	timestamp;

	(void)philo;
	(void)num_fork;
	if (!get_timestamp(&timestamp))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
	printer_write(philo, timestamp - philo->time_of_start, "has taken a fork");
	return (true);
}

static bool philo_leave_fork(t_philosopher *philo, size_t num_fork)
{
	//t_milisecs	timestamp;

	(void)philo;
	(void)num_fork;
//	if (!get_timestamp(&timestamp))
//		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
//	printer_write(philo, timestamp - philo->time_of_start, "has taken a fork");
	return (true);	
}

static bool	philo_eating_time(t_philosopher *philo)
{
	t_milisecs	timestamp;
	
	if (!get_timestamp(&timestamp))
		return (ft_putendl(STDERR_FILENO, "ERROR AT get_timestamp."), false);
	printer_write(philo, timestamp - philo->time_of_start, "is eating");
	threads_sleep(philo->rules->time_to_eat * 1000);
	return (true);
}

bool	philo_eat(t_philosopher *philo)
{
	if (!philo_take_fork(philo, 1))
		return (false);	
	if (!philo_take_fork(philo, 2))
		return (false);
	if (!philo_eating_time(philo))
		return (false);
	if (!philo_leave_fork(philo, 2))
		return (false);
	if (!philo_leave_fork(philo, 1))
		return (false);
	philo->status = EATING;
	if (philo->rules->number_of_meals > 0)
		if (!philo_inc_num_meal(&philo->mtx_num_meals))
			return (false);
	return (true);
}