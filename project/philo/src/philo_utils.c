/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:39:35 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/19 23:23:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#include "utils.h"
#include "simulation.h"
#include "philosopher.h"
#include "fork.h"

static bool	philo_init(t_simulation *simulation, size_t num_philo)
{
	t_philosopher	*philo;
	size_t			total_philos;

	total_philos = simulation->rules.number_of_philos;
	philo = simulation->philos + num_philo;
	philo->num_philo = num_philo + 1;
	philo->r_fork = &simulation->forks[num_philo];
	if (total_philos == 1)
		return (true);
	if (num_philo == 0)
		philo->l_fork = &simulation->forks[total_philos - 1];
	else
		philo->l_fork = &simulation->forks[num_philo - 1];
	if (pthread_mutex_init(&philo->mutex_time_2_eat, NULL) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error at mutex init.");
		return (false);
	}
	return (true);
}


bool	philos_init(t_simulation *simulation)
{
	size_t	i;

	simulation->philos = (t_philosopher *)malloc( \
							simulation->rules.number_of_philos * \
								sizeof(t_philosopher));
	if (simulation->philos == NULL)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error at memory malloc.");
		return (false);
	}
	i = 0;
	while (i < simulation->rules.number_of_philos)
	{
		if (!philo_init(simulation, i))
		{
			philos_destroy(simulation, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static	bool	philo_destroy(t_philosopher *philo)
{
	if (pthread_mutex_destroy(&philo->mutex_time_2_eat) < 0)
	{
		ft_putendl(STDERR_FILENO, "ERROR: Error at mutex destroy.");
		return (false);
	}
	return (true);
}

bool	philos_destroy(t_simulation *simulation, size_t total)
{
	size_t	i;

	i = 0;
	while (i < total)
	{
		philo_destroy(simulation->philos + i);
		i++;
	}
	ft_free (simulation->philos);
	return (true);
}
