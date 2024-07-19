/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:38:05 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/19 22:51:33 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"
#include "simulation.h"
#include "fork.h"
#include "philosopher.h"

t_simulation	simulation_new(void)
{
	t_simulation	simulation;
	
	simulation.forks 			= NULL;
	simulation.philos 			= NULL;
	simulation.run				= false;
	simulation.time_of_start	= 0;
	return (simulation);
}

void	simulation_destroy(t_simulation *simulation)
{
	forks_destroy(simulation, simulation->rules.number_of_philos);
	philos_destroy(simulation, simulation->rules.number_of_philos);
	if (pthread_mutex_destroy(&simulation->mutex_print) < 0)
		ft_putendl(STDERR_FILENO, "ERROR: Error destroying mutex.");
}


bool	simulation_init(t_simulation *simulation)
{
	if (pthread_mutex_init(&simulation->mutex_print, NULL) < 0)
		return (ft_putendl(STDERR_FILENO, "ERROR: Creating mutex of print."), \
					false);
	if (!forks_init(simulation))
		return (false);
	if (!philos_init(simulation))
		return (false);
	return (true);
}