/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:28:36 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 19:54:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philosopher.h"
#include "timestamp.h"
#include "printer.h"

void	*philo_life(void * arg)
{
	t_philosopher	*philo;
	t_milisecs		timestamp;

	philo = (t_philosopher *)arg;
	if (!get_timestamp(&timestamp))
	{
		printf("ERROR AT get_timestamp.\n");
		return	(NULL);
	}
	printf("JAJAJAJA\n");
	printer_write(philo, timestamp - philo->time_of_start, "Hola mundo!\n");
	return (arg);
}