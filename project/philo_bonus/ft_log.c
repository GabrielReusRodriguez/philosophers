/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:58:47 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/12 13:08:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include "ft_philosopher.h"
#include "ft_timestamp.h"

void	ft_log(t_philosopher *philo, const char *msg, t_timestamp time)
{
	sem_wait(philo->sem_console);
	printf("%llu", time);
	printf(" %d ", philo->number);
	printf("%s\n", msg);
	sem_post(philo->sem_console);
}
