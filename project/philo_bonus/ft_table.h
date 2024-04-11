/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:50:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 20:27:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>
# include <semaphore.h>
# include "ft_philosopher.h"
# include "ft_utils.h"
# include "ft_args.h"
# include "ft_rules.h"
# include "ft_semaphores.h"

typedef struct s_table
{
	size_t              num_forks;
    t_philosopher_set	philosophers_set;
	t_rules				rules;
	t_timestamp			start_time;
    sem_t               *sem_end;
    sem_t               *sem_dead;
    sem_t               *sem_meal;
    sem_t               *sem_console;
    sem_t               *sem_forks;
    pid_t               process_list;
}	t_table;

void	ft_table_destroy(t_table *table);
//t_bool	ft_table_pickup_forks(t_table *table, int num_philosopher);
t_bool	ft_table_isdead(void);
t_table	ft_table_init(t_args args);

#endif