/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:21:52 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 00:37:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philosopher.h"
#include "ft_table.h"
#include "ft_timestamp.h"

int ft_threads_check_philo_dead(t_philosopher *philo)
{
    t_timestamp now;
    
    while(TRUE)
    {
        now = ft_timestamp_get();
        if (now - philo->meals.timestamp >= philo->rules.time_to_die)
        {
            sem_post(philo->sem_end);
            exit(EXIT_SUCCESS);
        }
    }
    return (0);
}

int ft_threads_check_philo_meal(t_philosopher *philo)
{
    size_t  num_meals;

    num_meals = 0;
    while(TRUE)
    {
        if (philo->meals.num_meals >= philo->rules.number_eats)
        {
            sem_post(philo->sem_meal);
            break;
        }
    }
    return (0);
}

int ft_threads_check_meals(t_table *table)
{
    size_t  i;

    i = 0;
    while (i < table->philosophers_set.total)
    {
        sem_wait(table->sem_meal);
        i++;
    }
    //call to kill  pids function
}

int ft_threads_check_deads(t_table *table)
{
    sem_wait(table->sem_end);
    //call to kill  pids function
}