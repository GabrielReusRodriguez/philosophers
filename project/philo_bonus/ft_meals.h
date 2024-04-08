/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:25:15 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/07 23:29:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEALS_H
# define FT_MEALS_H

# include "ft_timestamp.h"

typedef struct s_meals
{
	t_timestamp		timestamp;
	int				num_meals;
}	t_meals;


#endif