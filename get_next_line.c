/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/10 23:20:58 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_add_read_line(t_list **list, int fd)
{
	char	*str;
	int	rd;

	rd = 1;
	while (rd != 0 && ft_find_list_n(list) == 0)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
		{
			ft_free_list(list);
			return ;
		}
		rd = read(fd, str, BUFFER_SIZE);
		if (!rd)
		{
			free(str);
			ft_free_list(list);
			return ;
		}
		str[rd] = '\0';
		if (ft_add_str_list(list, str) == 0)
			return ;
	}
}

int	ft_count_str_size(t_list	**list)
{
	t_list	*tmp;
	int		i;
	int		count;
	
	tmp = *list;
	count = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == '\n')
				return (count + 1);
			i++;
			count++;
		}
		tmp = tmp->next;
	}
	return (count);
}

char	*ft_trim_str(t_list **list)
{
	t_list	*tmp;
	char	*str;
	int		i;
	int		size;
	int		j;
	
	if (*list == NULL)
		return (NULL);
	tmp = *list;
	size = ft_count_str_size(list);
	str = malloc(sizeof(char) * size);
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && size > j)
		{
			str[j] = tmp->content[i];
			i++;
			j++;
		}
		tmp = tmp->next;
	}
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;
	t_list			*tmp;
	
	if (list)
	{
		tmp = list;
		ft_next_iterre(&tmp);
	}
	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	ft_add_read_line(&list, fd);
	if (tmp)
		ft_add_front(&list, &tmp);
	str = ft_trim_str(&list);
	return (str);
}
