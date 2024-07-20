/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:30:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/07/20 19:06:18 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdbool.h>
# include <pthread.h>

# include "datatypes.h"
# include "philosopher.h"

bool	printer_write(t_philosopher *philo, t_milisecs time, \
			const char *msg);
#endif