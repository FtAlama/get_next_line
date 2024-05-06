/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/06 21:27:28 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_creat_next_line(t_list **list, int fd)
{
	int	rd;
	
	(*list)->content = malloc(BUFFER_SIZE);
	while (find_n((*list)->content) < 0)
	{
		
	}
}

char	*get_next_line(int fd)
{
	static t_list *list;
	
	ft_creat_next_line();
}
