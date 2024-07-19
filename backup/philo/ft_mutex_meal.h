/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_meal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:25:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/07 23:17:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_MEAL_H
# define FT_MUTEX_MEAL_H

# include <pthread.h>
# include "ft_timestamp.h"

typedef struct s_mutex_meal
{
	t_timestamp		timestamp;
	int				num_meals;
	pthread_mutex_t	mutex;
}	t_mutex_meal;

//int				ft_mutex_meal_get_num(t_mutex_meal *meal);
//t_timestamp		ft_mutex_meal_get_time(t_mutex_meal *meal);
/*void			ft_mutex_meal_set_time(t_mutex_meal *meal, \
					t_timestamp timestamp);
void			ft_mutex_meal_set_num(t_mutex_meal *meal);
*/
void			ft_mutex_meal_init(t_mutex_meal *meal);
void			ft_mutex_meal_destroy(t_mutex_meal *meal);
void			ft_mutex_meal_update(t_mutex_meal *meal, t_timestamp timestamp);

#endif