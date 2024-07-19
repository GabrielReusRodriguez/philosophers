/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/04 23:45:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "ft_args.h"
#include "ft_thread.h"
#include "ft_philosopher.h"

/*
	This function checks death condition and number of meals
	(if it is informed) of a philosopher.
	It prints 
*/
int	ft_main_check_philo(t_philosopher *philo, t_bool *bn_meals)
{
	t_timestamp	now;
	t_timestamp	last_meal_time;
	int			number_meals;
	t_rules		rules;

	rules = philo->rules;
	number_meals = ft_mutex_meal_get_num(&philo->meals);
	if (rules.number_eats > 0 && number_meals >= rules.number_eats)
		*bn_meals = TRUE;
	else
		*bn_meals = FALSE;
	now = ft_timestamp_get();
	last_meal_time = ft_mutex_meal_get_time(&philo->meals);
	if (now - last_meal_time >= rules.time_to_die)
	{
		ft_thread_printf(philo, "died", now - philo->start_time);
		ft_mutex_bvalue_set(philo->end, TRUE);
		return (1);
	}
	return (0);
}

/*
	This function checks all the philosophers calling ft_main_check_philo
	for each philosopher.
*/
void	ft_main_check_simulation(t_table *table)
{
	int			i;
	t_bool		bn_meals;
	t_bool		b_philo_n_meal;

	i = 0;
	bn_meals = TRUE;
	b_philo_n_meal = FALSE;
	while ((size_t)i < table->philosophers_set.total)
	{
		if (ft_main_check_philo(&table->philosophers_set.philosophers[i], \
				&b_philo_n_meal) == 1)
			return ;
		bn_meals = bn_meals && b_philo_n_meal;
		i++;
		ft_thread_sleep(500);
	}
	if (table->rules.number_eats > 0 && bn_meals == TRUE)
		ft_mutex_bvalue_set(&table->end, TRUE);
}

/*
	This function runs simulation until an end condition is found.
*/
void	ft_main_run_simulation(t_table *table)
{
	while (ft_mutex_bvalue_get(&table->end) == FALSE)
	{
		ft_main_check_simulation(table);
	}
}

/*
	This function checks if the forks and the philosophers were
	initialized correct. If not, it destroys and free resources.
*/
int	ft_main_check_init(t_table *table)
{
	if (table->philosophers_set.philosophers == NULL || \
			table->forks_set.forks == NULL)
	{
		ft_table_destroy(table);
		return (-1);
	}
	return (1);
}

/*
	main does:
		1. Validate format of args.
		2. Validate value of args.
		3. Initializes the table structure
		4. Validate table has created fine.
		5. Create threads, one per philosopher.
		6. Run simulation (it will check end conditions infinte...)
		7. Finally do the join of threads to free resorces.
		8. Free table resources.
*/
int	main(int argc, char **argv)
{
	t_args		args;
	t_table		table;

	if (ft_args_validate_format(argv, argc) == FALSE)
		return (EXIT_FAILURE);
	args = ft_args_parse(argv, argc);
	if (ft_args_validate_value(args) == FALSE)
		return (EXIT_FAILURE);
	table = ft_table_init(args);
	if (ft_main_check_init(&table) == -1)
		return (EXIT_FAILURE);
	ft_thread_create_threads(&table);
	ft_main_run_simulation(&table);
	ft_thread_join_threads(&table.philosophers_set);
	ft_table_destroy(&table);
	return (0);
}
