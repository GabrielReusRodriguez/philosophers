/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semaphores.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:12:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/10 23:42:06 by gabriel          ###   ########.fr       */
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

#endif