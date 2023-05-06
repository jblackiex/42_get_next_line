/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:04:01 by nbordoni          #+#    #+#             */
/*   Updated: 2022/11/11 11:04:04 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buffer_fd(char *buffer, int fd)
{
	if (buffer == NULL || fd == -1)
	{
		if (buffer != NULL)
			free(buffer);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*buffer;
	int		count;

	i = 0;
	count = 1;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (check_buffer_fd(buffer, fd))
		return (NULL);
	buffer[0] = 0;
	while (i < BUFFER_SIZE
		&& (count == read(fd, &buffer[i], BUFFER_SIZE - BUFFER_SIZE + 1)))
	{
		if (count == -1)
			return (ft_free(buffer));
		else if (buffer[i] == '\n')
			return (not_n2(buffer, i + 1));
		i++;
	}
	if (!i)
		return (ft_free(buffer));
	if (!count)
		return (not_n2(buffer, i));
	else
		return (not_n(fd, buffer, i));
}
