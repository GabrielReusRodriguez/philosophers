/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:12:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/12 14:31:46 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEMAPHORES_H
# define FT_SEMAPHORES_H

# define SEMAPHOR_FORKS     "semaphor_forks"
# define SEMAPHOR_DEAD      "semaphor_dead"
# define SEMAPHOR_END       "semaphor_end"
# define SEMAPHOR_MEALS     "semaphor_meals"
# define SEMAPHOR_CONSOLE   "semaphor_console"

sem_t	*ft_semaphore_create(char *name, int value);
void	ft_semaphore_destroy(char *sem_name, sem_t *sem_value);

#endif