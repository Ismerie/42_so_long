/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:49:25 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/16 19:49:25 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_size_file(char *file)
{
	int		octet;
	int		size;
	int		fd;
	char	buff[1];

	size = 0;
	octet = 1;
	fd = open(file, O_RDONLY);
	while (octet != 0)
	{
		octet = read(fd, buff, 1);
		if (octet == -1)
			return (0);
		size++;
	}
	return (size);
}

char	*read_file(char *file)
{
	int		fd;
	int		size_file;
	char	*buff;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	size_file = ft_size_file(file);
	buff = malloc(sizeof (char) * (size_file + 1));
	if (!buff)
		return (0);
	size_file = read(fd, buff, size_file);
	if (size_file == -1)
		return (0);
	buff[size_file] = '\0';
	close (fd);
	return (buff);
}
