/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:00:45 by lelanglo          #+#    #+#             */
/*   Updated: 2024/11/25 14:58:36 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit_str(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (0);
		i++;
	}
	i = 0;
	while (argv[2][i])
		i++;
	return (i + 1);
	return (0);
}
