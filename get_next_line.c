/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/14 20:25:38 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_add_str_buffer_size(char *str, int fd)
{
	char	*buffer;
	char	*tmp;
	int		rd;

	while (ft_find_line(str) == -1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			ft_free(&str);
			ft_free(&buffer);
		}
		if (rd == 0)
			break ;
		buffer[rd] = '\0';
		tmp = str_join(str, buffer, rd);
		str = tmp;
		tmp = NULL;
	}
	if (rd == 0)
		ft_free(&buffer);
	return (str);
}

char	*str_trim(char *str)
{
	char	*buffer;
	int		i;
	int		tmp;

	tmp = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[tmp] != '\n' && str[tmp] != '\0')
		tmp++;
	if (str[tmp] == '\n')
		buffer = malloc(sizeof(char) * (tmp + 2));
	else
		buffer = malloc(sizeof(char) * (tmp + 1));
	i = 0;
	while (i < tmp)
	{
		buffer[i] = str[i];
		i++;
	}
	if (str[tmp] == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_free(&str);
		return (NULL);
	}

	if (str == NULL)
	{
		str = malloc(sizeof(char) * 1);
		if (!str) return (NULL);
		str[0] = '\0';
	}
	str = ft_add_str_buffer_size(str, fd);
	buffer = str_trim(str);
	str = next_line(str);
	if (ft_find_line(buffer) == -1)
		ft_free(&str);
	return (buffer);
}
