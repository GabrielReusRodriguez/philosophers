/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:53:20 by greus-ro          #+#    #+#             */
/*   Updated: 2024/04/02 18:41:55 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "ft_rules.h"

t_rules	ft_rules_init(t_args args)
{
	t_rules	rules;

	rules.number_eats = args.num_must_eat;
	rules.time_to_die = args.time_to_die;
	rules.time_to_eat = args.time_to_eat;
	rules.time_to_sleep = args.time_to_sleep;
	return (rules);
}

/*
t_rules	ft_rules_init(t_args args)
{
	t_rules rules;

	rules.number_eats	= args.num_must_eat;
	rules.time_to_die	= args.time_to_die;
	rules.time_to_eat	= args.time_to_eat;
	rules.time_to_sleep = args.time_to_sleep;
	rules.log = NULL;
	pthread_mutex_init(rules.log, NULL);
	return (rules);
}
*/
/*
void	ft_rules_destroy(t_rules *rules)
{
	//pthread_mutex_destroy(&rules->log);
	free (rules);
}
*/