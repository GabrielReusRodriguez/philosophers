/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:53:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 22:23:02 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <semaphore.h>
#include "ft_table.h"
#include "ft_args.h"
#include "ft_semaphores.h"

void	ft_table_destroy(t_table *table)
{
	if (table->philosophers_set.philosophers != NULL)
	{
		ft_philosophers_destroy(&table->philosophers_set);
	}
    sem_close(table->sem_console);
    sem_close(table->sem_meal);
    sem_close(table->sem_forks);
    sem_close(table->sem_dead);
    sem_close(table->sem_end);
}

/*
t_bool	ft_table_pickup_forks(t_table *table, int num_philosopher)
{
   (void) table;
   num_philosopher++;
	return (TRUE);
}
*/
t_table	ft_table_init(t_args args)
{
	t_table	table;

	table.rules = ft_rules_init(args);
    table.num_forks = args.num_philo;
	table.philosophers_set = ft_philosophers_init(args, \
								table.rules);
    table.sem_console = sem_open(SEMAPHOR_CONSOLE, O_CREAT, 0644, 1);
    sem_unlink(SEMAPHOR_CONSOLE);
    table.sem_meal = sem_open(SEMAPHOR_MEALS, O_CREAT, 0644, args.num_philo);
    sem_unlink(SEMAPHOR_MEALS);
    table.sem_forks = sem_open(SEMAPHOR_FORKS, O_CREAT, 0644, args.num_philo);
    sem_unlink(SEMAPHOR_FORKS);
    table.sem_dead = sem_open(SEMAPHOR_DEAD, O_CREAT, 0644, 1);                    
    sem_unlink(SEMAPHOR_DEAD);
    table.sem_end = sem_open(SEMAPHOR_END, O_CREAT, 0644, 1);                    
    sem_unlink(SEMAPHOR_END);
	return (table);
}
