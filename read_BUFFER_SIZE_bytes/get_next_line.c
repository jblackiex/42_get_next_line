/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:41:08 by nbordoni          #+#    #+#             */
/*   Updated: 2023/05/06 15:41:09 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *remain, char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*arr;

	if (!remain && !buffer)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(remain) + ft_strlen(buffer);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (remain && remain[i])
		arr[j++] = remain[i++];
	i = 0;
	while (buffer[i])
		arr[j++] = buffer[i++];
	arr[j] = '\0';
	free ((void *)remain);
	return (arr);
}

char	*save_line(char *remain)
{
	int		i;
	char	*arr;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (remain[i] == '\n')
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (remain[++i] && remain[i] != '\n')
		arr[i] = remain[i];
	if (remain[i] == '\n')
		arr[i++] = '\n';
	arr[i] = '\0';
	return (arr);
}

char	*trim_line(char *remain)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!remain[i])
	{
		free (remain);
		return (NULL);
	}
	arr = (char *)malloc(sizeof(char) * (ft_strlen(remain) - i + 1));
	if (!arr)
		return (NULL);
	i++;
	while (remain[i])
		arr[j++] = remain[i++];
	arr[j] = '\0';
	free (remain);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buffer;
	char		*line;
	int			rd;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	rd = 1;
	while (!find_n(buffer) && rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	line = save_line(remain);
	remain = trim_line(remain);
	return (check_0_line (line, buffer));
}
