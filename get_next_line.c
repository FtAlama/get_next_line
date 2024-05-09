/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:52:02 by alama             #+#    #+#             */
/*   Updated: 2024/05/07 21:58:54 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static void	ft_add_back_list(t_list **list, char *str)
{
	t_list	*new;
	t_list	*tmp_list;

	if(!list || !str)
		return ;
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	new = malloc(sizeof(t_list));
	if (tmp_list == NULL)
		*list = new;
	else
		tmp_list->next = new;
	new->content = str;
	new->next = NULL;
}

static void	ft_creat_next_line(t_list **list, int fd)
{
	int	rd;
	char	*str;
	t_list	*tmp_list;

	tmp_list = *list;
	str = NULL;
	while (find_n(str) == 0)
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
		tmp_list = tmp_list->next;
	}
}

static void	ft_strdup_list(t_list **list, char **str)
{
	int	i;
	int	j;
	t_list	tmp_list;

	i = 0;
	j = 0;
	tmp_list = *list;
	while (tmp_list)
	{
		while (tmp_list->content[j] != '\0' && tmp_list->content[j] != '\n')
		{
			j++;
			i++;
		}
		tmp_list = tmp_list->next;
	}
	*str = malloc(sizeof(char) * (j + 1));
}

static char	*ft_cpy_list_str(t_list **list, char *str)
{
	t_list	tmp;
	int	i;
	int	j;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		j = 0;
		while (tmp->content)
		{
			str[i] = tmp->content[j];
			j++;
			i++;
		}
		tmp = tmp->next;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list *list;
	char	*next_line;

	list = NULL;
	ft_creat_next_line(&list, fd);
	if (!list)
		return (NULL);
	ft_strdup_list(&list, *next_line);
	if (!next_line)
		return ;
	next_line = ft_cpy_list_str(&list, *next_line);
}
