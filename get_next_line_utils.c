/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:40:51 by alama             #+#    #+#             */
/*   Updated: 2024/05/10 23:20:49 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free_list(t_list **list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = *list;
		free((*list)->content);
		*list = (*list)->next;
		free(tmp);
	}
}

int	ft_add_str_list(t_list **list, char *str)
{
	t_list	*tmp;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		ft_free_list(list);
		return (0);
	}
	new->content = str;
	new->next = NULL;
	tmp = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int	ft_find_list_n(t_list **list)
{
	t_list	*tmp;
	int	i;

	if (!list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] == '\n')
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_next_iterre(t_list **list)
{
	char	*str;
	t_list	*tmp;
	int		i;
	int		j;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	i = 0;
	while (tmp->content[i] && tmp->content[i] != '\n')
		i++;
	j = i;
	while (tmp->content[i])
		i++;
	str = malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (tmp->content[j])
	{
		str[i] = tmp->content[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free(tmp->content);
	tmp->content = str;	
}

void	ft_add_front(t_list **list, t_list **new)
{
	t_list	*tmp;
	t_list	*last_new;
	
	last_new = *new;
	while (last_new->next)
		last_new = last_new->next;
	tmp = *list;
	*list = last_new;
	(*list)->next = tmp;
}
