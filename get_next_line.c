/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/02 22:23:00 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char *str, int index)
{
	while (index >= 0)
	{
		free(str + index);
		index--;
	}
}

char	*get_next_line(int fd)
{
	char	*str;
	int		rd;
	int		index;
	
	rd = 1;
	str = malloc(sizeof(char *) * 10000);
	if (!str)
		return (NULL);
	index = 0;
	while (rd != 0)
	{
		rd = read(fd, str + index, 1);
		if (rd == -1)
			return (free(str), NULL);
		if (*(str + index) == '\n')
			break;
		index++;
	}
	str[index] = '\0';
	return (str);
}
