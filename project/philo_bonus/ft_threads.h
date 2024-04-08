/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:17:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/09 00:36:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADS_H
# define FT_THREADS_H

# include "ft_table.h"
# include "ft_philosopher.h"

int ft_threads_check_philo_dead(t_philosopher *philo);
int ft_threads_check_philo_meal(t_philosopher *philo);
int ft_threads_check_meals(t_table *table);
int ft_threads_check_deads(t_table *table);

#endif