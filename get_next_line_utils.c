/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:40:51 by alama             #+#    #+#             */
/*   Updated: 2024/05/13 16:10:47 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_join(char *str, char *buffer, int rd)
{
	char	*join;
	int	i;
	int	j;
	
	//printf("%d		-		%d\n", ft_strlen(str), ft_strlen(buffer));
	join = malloc(sizeof(char) * (ft_strlen(str) + rd + 1));
	j = 0;
	i = 0;
	while (str[i])
	{
		join[j] = str[i];
		i++;
		j++;	
	}
	i = 0;
	while (i < rd)
	{
		join[j] = buffer[i];
		i++;
		j++;
	}
	join[j] = '\0';
	free(str);
	free(buffer);
	return (join);
}


int	ft_find_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*next_line(char *str)
{
	char	*tmp;
	int		i;
	int		j;
	
	i = ft_find_line(str) + 1;
	j = i;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (str[j])
	{
		tmp[i] = str[j];
		j++;
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
