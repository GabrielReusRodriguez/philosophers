/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 23:50:24 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/04 23:51:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_fork.h"
#include "ft_timestamp.h"

t_fork_set	ft_forks_init(size_t total)
{
	size_t		i;
	t_fork_set	_forks;

	_forks.forks = (t_fork *)malloc(total * sizeof(t_fork));
	if (_forks.forks == NULL)
	{
		_forks.forks = 0;
		return (_forks);
	}
	memset(_forks.forks, 0, total * sizeof(t_fork));
	i = 0;
	while (i < total)
	{
		_forks.forks[i].num_fork = i;
		if (pthread_mutex_init(&_forks.forks[i].mutex, NULL) < 0)
		{
			ft_forks_destroy(&_forks);
			return (_forks);
		}
		i++;
	}
	_forks.num_forks = total;
	return (_forks);
}

void	ft_forks_destroy(t_fork_set *_forks)
{
	size_t	i;

	if (_forks->forks != NULL)
	{
		i = 0;
		while (i < _forks->num_forks)
		{
			pthread_mutex_destroy(&_forks->forks[i].mutex);
			i++;
		}
		free (_forks->forks);
		_forks->forks = NULL;
		_forks->num_forks = 0;
	}
}

int	ft_fork_pickup(t_fork *fork, int philosopher, int hand)
{
	int	mutex_return;

	if (fork != NULL)
	{
		mutex_return = pthread_mutex_lock(&fork->mutex);
		fork->philosopher = philosopher;
		fork->hand = hand;
		return (mutex_return);
	}
	return (0);
}

int	ft_fork_drop(t_fork *fork)
{
	int	mutex_return;

	if (fork != NULL)
	{
		fork->philosopher = -1;
		fork->hand = -1;
		mutex_return = pthread_mutex_unlock(&fork->mutex);
		return (mutex_return);
	}
	return (0);
}
