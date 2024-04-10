/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:42:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 00:09:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
