/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:17:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 21:08:22 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADS_H
# define FT_THREADS_H

# include "ft_table.h"
# include "ft_philosopher.h"

void    *ft_threads_check_philo_dead(void *args);
void    *ft_threads_check_philo_meal(void *args);
//int ft_threads_check_meals(t_table *table);
//int ft_threads_check_deads(t_table *table);
void    *ft_threads_check_philo_dead(void *args);
void    *ft_threads_check_philo_meal(void * args);



#endif