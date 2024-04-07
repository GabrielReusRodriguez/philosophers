/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:53:56 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 21:08:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "ft_table.h"
#include "ft_args.h"

void	ft_table_destroy(t_table *table)
{
	if (table->forks_set.forks != NULL)
	{
		ft_forks_destroy(&table->forks_set);
	}
	if (table->philosophers_set.philosophers != NULL)
	{
		ft_philosophers_destroy(&table->philosophers_set);
	}
	pthread_mutex_destroy(&table->log.mutex);
	pthread_mutex_destroy(&table->end.mutex);
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
	table.forks_set = ft_forks_init(args.num_philo);
	table.philosophers_set = ft_philosophers_init(args, table.forks_set, \
								table.rules);
	table.end = ft_mutex_bvalue_init(FALSE);
	table.log = ft_mutex_bvalue_init(TRUE);
	return (table);
}
