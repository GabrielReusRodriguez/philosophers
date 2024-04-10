/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:58:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 00:01:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include "ft_philosopher.h"
#include "ft_timestamp.h"

void    ft_log(t_philosopher *philo, const char *msg , t_timestamp time)
{
	sem_wait(philo->sem_console);
	printf("%llu", time);
	printf(" %d ", philo->number);
	printf("%s\n", msg);
	sem_post(philo->sem_console);

}