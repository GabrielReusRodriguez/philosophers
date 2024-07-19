/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:19:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 18:14:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREAD_H
# define FT_THREAD_H

# include "ft_philosopher.h"
# include "ft_table.h"

int		ft_thread_sleep(int milliseconds);
int		ft_thread_create_threads(t_table *table);
int		ft_thread_join_threads(t_philosopher_set *philo);
void	ft_thread_printf(t_philosopher *philo, char *str, t_timestamp time);

#endif