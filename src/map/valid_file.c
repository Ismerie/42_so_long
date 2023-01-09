/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:57:25 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/22 17:57:25 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	valid_file(int argc, char *argv)
{
	int	size;

	if (argc == 1)
	{
		ft_printf("Error\nThere are no argument\n");
		return (0);
	}
	if (argc > 2)
		ft_printf("Only the first file would be used\n");
	size = ft_strlen(argv);
	size = size - 4;
	if (!strncmp(".ber", argv + size, 4))
	{
		ft_printf("Error\nThe map should be a .ber file\n");
		return (0);
	}
	return (1);
}
