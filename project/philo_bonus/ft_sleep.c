/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:24:21 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/07 19:35:41 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_timestamp.h"

/*
int	ft_sleep(unsigned long millisecs)
{
	t_timestamp	init_time;
	t_timestamp	now;
	int			err;

	init_time = ft_timestamp_get();
	now = init_time;
	while (now - init_time < millisecs)
	{
		err = usleep(500);
		if (err < 0)
			return (err);
		now = ft_timestamp_get();
	}
	return (0);
}
*/
int	ft_sleep(unsigned long millisecs)
{
	return (usleep(millisecs * 1000));
}
