/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_and_check_map_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:54:39 by mkorpela          #+#    #+#             */
/*   Updated: 2024/03/13 09:03:28 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strlen_until_newline_or_null_terminator(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != 10)
	{
		i++;
	}
	return (i);
}

int	calc_number_of_rows(char **array_of_map_rows)
{
	int	i;

	i = 0;
	while (array_of_map_rows[i])
	{
		i++;
	}
	return (i);
}
