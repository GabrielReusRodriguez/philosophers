/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:32:38 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 19:40:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex_meal.h"

int	ft_mutex_meal_get_num(t_mutex_meal *meal)
{
	int	num;

	pthread_mutex_lock(&meal->mutex);
	num = meal->num_meals;
	pthread_mutex_unlock(&meal->mutex);
	return (num);
}

t_timestamp	ft_mutex_meal_get_time(t_mutex_meal *meal)
{
	t_timestamp	time;

	pthread_mutex_lock(&meal->mutex);
	time = meal->timestamp;
	pthread_mutex_unlock(&meal->mutex);
	return (time);
}

void	ft_mutex_meal_set_time(t_mutex_meal *meal, t_timestamp timestamp)
{
	pthread_mutex_lock(&meal->mutex);
	meal->timestamp = timestamp;
	pthread_mutex_unlock(&meal->mutex);
}

void	ft_mutex_meal_set_num(t_mutex_meal *meal)
{
	pthread_mutex_lock(&meal->mutex);
	meal->num_meals++;
	pthread_mutex_unlock(&meal->mutex);
}
