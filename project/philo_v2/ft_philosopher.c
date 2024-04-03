/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:25:18 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 19:36:58 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_thread.h"
#include "ft_args.h"
#include "ft_philosopher.h"
#include "ft_timestamp.h"
#include "ft_sleep.h"

t_philosopher	ft_philosopher_new(size_t num_philo)
{
	t_philosopher	philosopher;

	philosopher.number = num_philo + 1;
	philosopher.status = PHILO_STATUS_INIT;
	philosopher.l_fork = NULL;
	philosopher.r_fork = NULL;
	philosopher.meals.num_meals = 0;
	philosopher.meals.timestamp = 0l;
	return (philosopher);
}

static	t_philosopher	ft_philosophers_copy_rules(size_t i, t_rules rules, \
							int total_philo, t_fork_set forks)
{
	t_philosopher	philo;

	philo = ft_philosopher_new(i);
	ft_mutex_meal_init(&philo.meals);
	philo.rules.number_eats = rules.number_eats;
	philo.rules.time_to_die = rules.time_to_die;
	philo.rules.time_to_eat = rules.time_to_eat;
	philo.rules.time_to_sleep = rules.time_to_sleep;
	philo.total = total_philo;
	if ((int)i == philo.total - 1)
	{
		philo.l_fork = &forks.forks[i];
		philo.r_fork = &forks.forks[0];
	}
	else
	{
		philo.l_fork = &forks.forks[i];
		if ((int)i + 1 < philo.total)
			philo.r_fork = &forks.forks[i + 1];
	}
	return (philo);
}

t_philosopher_set	ft_philosophers_init(t_args args, t_fork_set forks, \
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
									args.num_philo, forks);
		i++;
	}
	return (philo);
}

/*
void	ft_philosopher_free(t_philosopher *philosophers)
{
	philosophers++;
}
*/
void	ft_philosophers_destroy(t_philosopher_set *philo)
{
	if (philo->philosophers != NULL)
	{
		free (philo->philosophers);
		philo->philosophers = NULL;
	}
}
