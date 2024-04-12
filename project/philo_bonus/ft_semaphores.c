/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:42:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/12 14:31:06 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/*
	With O_CREAT we say to sem_open to open the name semaphoner or create 
		if it does not exists.
	If we add O_EXCL to O_CREAT  we return an error if a semaphore with 
		name already exists.
	0644 are the permission to the semaphore (user, group, others...)
*/
sem_t	*ft_semaphore_create(char *name, int value)
{
	sem_t	*semaphore;

	sem_unlink(name);
	semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (semaphore == SEM_FAILED)
	{
		printf("ERROR creating semaphore %s\n", name);
		exit(EXIT_FAILURE);
	}
	return (semaphore);
}

/* If we do not use unlink before, the semaphore gets in some kind of
		cache and next time uses the last one.
		
	To be sure we have deleted the semaphore, the best is first unlink 
	(de-register de semaphore) and then close.*/
void	ft_semaphore_destroy(char *sem_name, sem_t *sem_value)
{
	sem_unlink(sem_name);
	sem_close(sem_value);
}
