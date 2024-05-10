/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/10 15:24:23 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	find_n(t_list **list)
{
	t_list	*tmp;
	int		i;

	if (*list == NULL)
		return (0);
	tmp = *list;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && i < BUFFER_SIZE)
		{
			if (tmp->content[i] == '\n')
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_add_back_list(t_list **list, char *str)
{
	t_list	*new;
	t_list	*tmp_list;

	if (!str)
		return ;
	//printf("%s\n", str);
	tmp_list = *list;
	new = malloc(sizeof(t_list));
	if (!new) // need free list
		return ;
	if (*list == NULL)
		(*list) = new;
	else
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = new;
	}
	new->content = str;
	new->next = NULL;
}

static void	ft_creat_next_line(t_list **list, int fd)
{
	int		rd;
	char	*str;

	str = NULL;
	rd = 1;
	while (!find_n(list) && rd != 0)
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return ;
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return ;
		}
		str[rd] = '\0';
		ft_add_back_list(list, str);
	}
}

static void	ft_strdup_list(t_list **list, char **str)
{
	int		i;
	int		j;
	t_list	*tmp_list;

	i = 0;
	tmp_list = *list;
	while (tmp_list)
	{
		j = 0;
		while (tmp_list->content[j] && tmp_list->content[j] != '\n')
		{
			j++;
			i++;
		}
		tmp_list = tmp_list->next;
	}
	*str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
}

static char	*ft_cpy_list_str(t_list **list, char *str)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!list || !str)
		return (NULL);
	tmp = *list;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] && tmp->content[j] != '\n')
		{
			str[i] = tmp->content[j];
			j++;
			i++;
		}
		if (tmp->content[j] == '\n')
			str[i] = '\n';
		tmp = tmp->next;
	}
	i++;
	str[i] = '\0';
	return (str);
}


void	free_node(t_list **list)
{
	t_list	*tmp;

	while ((*list)->next != NULL)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
void	adjust_list(t_list **list)
{
	char	*str;
	int	i;
	int	j;

	i = 0;
	while ((*list)->content[i] && (*list)->content[i] != '\n')
		i++;
	j = i;
	while ((*list)->content[i])
		i++;
	str = malloc(sizeof(char) * (i - j + 1));
	i = j + 1;
	j = 0;
	while ((*list)->content[i])
	{
		str[j] = (*list)->content[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free((*list)->content);
	(*list)->content = str;
}

char	*ft_strjoin_str_to_list(t_list **list, char *next_line)
{
	char	*str;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while ((*list)->content[i])
	{
		i++;
		j++;
	}
	i = 0;
	while (next_line[i])
	{
		i++;
		j++;
	}
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((*list)->content[i])
	{
		str[i] = (*list)->content[i];
		i++;
	}
	while (next_line[j])
	{
		str[i] = next_line[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(next_line);
	free((*list)->content);
	(*list)->next = NULL;
	free(*list);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	t_list	*tmp;

	if (list)
	{
		free_node(&list);
		tmp = list;
		adjust_list(&tmp);
	}
	list = NULL;
	ft_creat_next_line(&list, fd);
	if (list == NULL)
		return (NULL);
	ft_strdup_list(&list, &next_line);
	if (!next_line)
		return (NULL);
	next_line = ft_cpy_list_str(&list, next_line);
	if (tmp)
		next_line = ft_strjoin_str_to_list(&tmp, next_line);
	return (next_line);
}
