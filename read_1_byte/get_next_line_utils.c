/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:04:17 by nbordoni          #+#    #+#             */
/*   Updated: 2022/11/11 11:04:19 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

void	*ft_memcpy(char *dest, char *src, size_t n)
{
	char		*d;
	char		*s;
	size_t		i;

	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_alloc(int h, int i, char *buffer, char d)
{
	char	*c;

	c = (char *) malloc ((h + i + 1) * sizeof (char));
	ft_memcpy(c, buffer, (h + i));
	free(buffer);
	c[h + i] = d;
	return (c);
}

char	*not_n2(char *buffer, int dim)
{
	char	*c;

	c = (char *) malloc ((dim + 1) * sizeof (char));
	if (c == NULL)
		return (NULL);
	ft_memcpy(c, buffer, (dim));
	free(buffer);
	c[dim] = '\0';
	return (c);
}

char	*not_n(int fd, char *buffer, int h)
{
	static int	i;
	char		*c;
	char		d;
	int			j;

	if (read(fd, &d, 1))
	{
		c = ft_alloc(h, i, buffer, d);
		i++;
		if (d == '\n')
		{
			j = i;
			i = 0;
			return (not_n2(c, (h + j)));
		}
		return (not_n(fd, c, h));
	}
	else if (!i)
		return (not_n2(buffer, h));
	else
	{
		j = i;
		i = 0;
		return (not_n2(buffer, (h + j)));
	}
}
