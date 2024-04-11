/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forkproc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:19:45 by gabriel           #+#    #+#             */
/*   Updated: 2024/04/11 20:39:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORKPROC_H
# define FT_FORKPROC_H

# include "ft_table.h"
# include  "ft_philosopher.h"

int	ft_forkproc_create_proc(t_table *table);
int	ft_forkproc_wait(t_philosopher_set philosophers);
int	ft_forkproc_killall(t_philosopher_set philosophers);


#endif