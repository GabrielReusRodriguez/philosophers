/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 08:34:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"

t_philosopher	ft_philosopher_new(size_t num_philo)
{
	t_philosopher	philosopher;

	philosopher.number = num_philo + 1;
	philosopher.status = PHILO_STATUS_INIT;
	philosopher.l_fork = FALSE;
	philosopher.r_fork = FALSE;
    philosopher.meals.num_meals = 0;
	philosopher.meals.timestamp = 0l;
	return (philosopher);
}

static	t_philosopher	ft_philosophers_copy_rules(size_t i, t_rules rules, \
							int total_philo)
{
	t_philosopher	philo;

	philo = ft_philosopher_new(i);
	philo.rules.number_eats = rules.number_eats;
	philo.rules.time_to_die = rules.time_to_die;
	philo.rules.time_to_eat = rules.time_to_eat;
	philo.rules.time_to_sleep = rules.time_to_sleep;
	philo.total = total_philo;
	philo.l_fork = 0;
	philo.r_fork = 0;
	return (philo);
}

t_philosopher_set	ft_philosophers_init(t_args args, \
						t_rules rules)
{
	t_philosopher_set	philo;
	size_t				i;

	philo.philosophers = (t_philosopher *)malloc(args.num_philo * \
								sizeof(t_philosopher));
	if (philo.philosophers == NULL)
		return (philo);
	philo.total = args.num_philo;
	i = 0;
	while (i < philo.total)
	{
		philo.philosophers[i] = ft_philosophers_copy_rules(i, rules, \
									args.num_philo);
		i++;
	}
	return (philo);
}


void	ft_philosopher_destroy(t_philosopher *philosopher)
{
	sem_close(philosopher->sem_console);
	sem_close(philosopher->sem_end);
	sem_close(philosopher->sem_forks);
	sem_close(philosopher->sem_meal);
}


void	ft_philosophers_destroy(t_philosopher_set *philo)
{
	size_t	i;

	if (philo->philosophers != NULL)
	{
		i = 0;
		while (i < philo->total)
		{
			ft_philosopher_destroy(philo->philosophers + i);
			i++;
		}
		free (philo->philosophers);
		philo->philosophers = NULL;
	}
}
