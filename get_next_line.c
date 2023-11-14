/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:48:49 by soksak            #+#    #+#             */
/*   Updated: 2023/11/14 14:42:02 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (buffer[0] == 0)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i += 1;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*create_line(int fd, char *buffer)
{
	int		readbyte;
	char	*temp;

	readbyte = 1;
	temp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && readbyte)
	{
		readbyte = read(fd, temp, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[readbyte] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*remove_line(char *buffer, size_t len)
{
	size_t	i;
	char	*newline;

	if (buffer[len] == 0)
	{
		free(buffer);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - len + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (buffer[len])
		newline[i++] = buffer[len++];
	newline[i] = '\0';
	free(buffer);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = create_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = take_line(buffer);
	buffer = remove_line(buffer, ft_strlen(line));
	return (line);
}
