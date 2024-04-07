/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_meal2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:32:38 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 19:23:02 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mutex_meal.h"

void	ft_mutex_meal_init(t_mutex_meal *meal)
{
	pthread_mutex_init(&meal->mutex, NULL);
}

void	ft_mutex_meal_destroy(t_mutex_meal *meal)
{
	pthread_mutex_destroy(&meal->mutex);
}

void	ft_mutex_meal_update(t_mutex_meal *meal, t_timestamp timestamp)
{
	pthread_mutex_lock(&meal->mutex);
	meal->timestamp = timestamp;
	meal->num_meals++;
	pthread_mutex_unlock(&meal->mutex);
}
