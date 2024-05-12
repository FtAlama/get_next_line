/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/12 22:08:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_add_str_buffer_size(char *str, int fd)
{
	char	*buffer;
	int		rd;

	rd = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rd > 0 && ft_find_line(str) == 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		str = str_join(str, buffer);
	}
	return (str);
}

char	*str_trim(char *str)
{
	char	*buffer;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i]) 
		i++;
	buffer = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char	*buffer;
	
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	str = ft_add_str_buffer_size(str, fd);
	buffer = str_trim(str);
	str = next_line(str);
	return (buffer);
}
