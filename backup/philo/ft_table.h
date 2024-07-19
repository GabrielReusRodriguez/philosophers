/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:50:54 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/02 18:39:38 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>
# include "ft_philosopher.h"
# include "ft_fork.h"
# include "ft_utils.h"
# include "ft_mutex_bflag.h"
# include "ft_args.h"
# include "ft_rules.h"

typedef struct s_table
{
	t_fork_set			forks_set;
	t_philosopher_set	philosophers_set;
	t_bool				start;
	t_mutex_bflag		end;
	t_mutex_bflag		log;
	t_rules				rules;
	t_timestamp			start_time;
}	t_table;

void	ft_table_destroy(t_table *table);
//t_bool	ft_table_pickup_forks(t_table *table, int num_philosopher);
t_bool	ft_table_isdead(void);
t_table	ft_table_init(t_args args);

#endif