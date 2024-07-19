/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:24:21 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/04 22:59:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_timestamp.h"

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
