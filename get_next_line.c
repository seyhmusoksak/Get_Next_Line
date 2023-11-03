/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soksak <soksak@42istanbul.com.tr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:48:49 by soksak            #+#    #+#             */
/*   Updated: 2023/11/01 22:55:40 by soksak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
	char			buff[BUFFER_SIZE];
	char			*line;
	static ssize_t	fileread;
	size_t			save;

	while(fileread = read(fd, buff, BUFFER_SIZE - 1) > 0)
	{
		
	}


}

int ft_checkline(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return(i);
}





int main()
{
	int fd = open("dosya.txt", O_CREAT | O_RDONLY, 0777);

	int i = 0;
	while (i <= 5)
	{
		get_next_line(fd);
	}
}

