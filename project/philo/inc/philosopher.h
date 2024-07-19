/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:53:44 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/19 23:25:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stddef.h>
# include "datatypes.h"

/* Forward declaration to avoid error between includes*/
typedef struct s_simulation t_simulation;
typedef struct s_fork		t_fork;

typedef enum e_philo_status
{
	SLEEPING,
	EATING,
	THINKING,
	DIED
} t_philo_status;

typedef struct s_philosopher
{
	size_t			num_philo;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_milisecs		time_last_eat;
	size_t			num_meals;
	t_philo_status	status;

	pthread_mutex_t	mutex_time_2_eat;
	pthread_t		thread_id;

}	t_philosopher;

bool	philos_init(t_simulation *simulation);
bool	philos_destroy(t_simulation *simulation, size_t total);

#endif
