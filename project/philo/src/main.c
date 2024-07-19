/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:48:04 by greus-ro          #+#    #+#             */
/*   Updated: 2024/07/19 22:50:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "rules.h"
#include "simulation.h"


static void	rules_debug(t_rules rules)
{
	printf("RULES**********************\n");
	printf("\tnumber of philosophers %lu\n", rules.number_of_philos);
	printf("\ttime to die %lu ms\n", rules.time_to_die);
	printf("\ttime to eat %lu ms\n", rules.time_to_eat);
	printf("\ttime to sleep %lu ms\n", rules.time_to_sleep);
	printf("\tnumber of meals %lu\n", rules.number_of_meals);
	printf("END RULES******************\n");

}
/*
	main does:
		1. Validate format of args.
		2. Validate value of args.
		3. Initializes the table structure
		4. Validate table has created fine.
		5. Create threads, one per philosopher.
		6. Run simulation (it will check end conditions infinte...)
		7. Finally do the join of threads to free resorces.
		8. Free table resources.
*/
int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (!rules_import_args(argc, argv, &simulation.rules))
		return (EXIT_FAILURE);
	simulation = simulation_new();
	if (!simulation_init(&simulation))
		return (simulation_destroy(&simulation), false);
	rules_debug(simulation.rules);
	simulation_destroy(&simulation);
	return (EXIT_SUCCESS);
}
