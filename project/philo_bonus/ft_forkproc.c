/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkproc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:21:09 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 21:38:36 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "ft_forkproc.h"
#include "ft_philosopher.h"
#include "ft_threads.h"

#include <stdio.h>


static void	ft_forkproc_copy_semaphores(t_table *table, t_philosopher *philo)
{
	philo->sem_console = table->sem_console;
	//philo->sem_end = table->sem_end;
	philo->sem_forks = table->sem_forks;
	philo->sem_meal = table->sem_meal;
	philo->sem_dead = table->sem_dead;
}

int	ft_forkproc_create_proc(t_table *table)
{
	size_t  		i;
	pid_t			pid;
	pthread_t		thread;
	t_philosopher	*philo;
	
	i = 0;
	table->start_time = ft_timestamp_get();
	while(i < table->philosophers_set.total)
	{
		philo = table->philosophers_set.philosophers + i;
		philo->start_time = table->start_time;
		ft_forkproc_copy_semaphores(table, philo);
		pid = fork();
		if (pid != 0)
		{
			if (pid < 0)
				return (-1);
			philo->process = pid;
		}
		else
		{
			//Creo los threads de checkeo.
			thread = pthread_create(&thread, NULL, ft_threads_check_philo_dead, philo);
			pthread_detach(thread);
			if (philo->rules.number_eats > 0)
			{
				thread = pthread_create(&thread, NULL, ft_threads_check_philo_meal, philo);
				pthread_detach(thread);
			}
			ft_philosopher_life((void *)philo);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (0);
}

int	ft_forkproc_wait(t_philosopher_set philosophers)
{
	size_t	i;
	int		status;

	i = 0;
	while (i < philosophers.total)
	{
		if (waitpid(philosophers.philosophers[i].process, &status, 0) < 0 )
			return (-1);
		i++;
	}
	return (0);
}

int	ft_forkproc_killall(t_philosopher_set philosophers)
{
	size_t	i;

	i = 0;
	while (i < philosophers.total)
	{
		if (kill(philosophers.philosophers[i].process, SIGKILL) < 0)
			return (-1); 
		i++;
	}
	return (0);
}