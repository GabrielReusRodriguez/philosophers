/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:14:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/19 23:10:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_args.h"
#include "ft_utils.h"

t_bool	ft_args_validate(char **argv, int argc)
{
	size_t	i;
	
	if (argc < 5 || argc > 6)
	{
		printf("ERROR: number or args invalid\n");
		return (FALSE);
	}
	i = 1;
	while (i < (size_t)argc)
	{
		if (ft_utils_contains_num(argv[i]) == FALSE)
		{
			printf("ERROR: arg %s is NOT valid\n", argv[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_args	ft_args_parse(char **argv, int argc)
{
	t_args	args;
	
	args.num_philo		=		ft_utils_atoi(argv[1]);
	args.time_to_die 	=		ft_utils_atoi(argv[2]);
	args.time_to_eat	=		ft_utils_atoi(argv[3]);
	args.time_to_sleep	=		ft_utils_atoi(argv[4]);
	if (argc == 6)
		args.num_must_eat	=	ft_utils_atoi(argv[5]);
	return (args);
}