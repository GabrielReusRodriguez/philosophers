/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_bflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:54:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 18:54:47 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "ft_mutex_bflag.h"

t_mutex_bflag	ft_mutex_bvalue_init(t_bool value)
{
	t_mutex_bflag	flag;

	flag.value = value;
	pthread_mutex_init(&flag.mutex, NULL);
	return (flag);
}

t_bool	ft_mutex_bvalue_get(t_mutex_bflag *flag)
{
	t_bool	value;

	pthread_mutex_lock(&flag->mutex);
	value = flag->value;
	pthread_mutex_unlock(&flag->mutex);
	return (value);
}

void	ft_mutex_bvalue_set(t_mutex_bflag *flag, t_bool new_value)
{
	pthread_mutex_lock(&flag->mutex);
	flag->value = new_value;
	pthread_mutex_unlock(&flag->mutex);
}

void	ft_mutex_bvalue_destroy(t_mutex_bflag *flag)
{
	pthread_mutex_destroy(&flag->mutex);
}
