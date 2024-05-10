/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:31:27 by alama             #+#    #+#             */
/*   Updated: 2024/05/10 23:20:54 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_find_list_n(t_list **list);
void	ft_add_read_line(t_list **list, int fd);
void	ft_free_list(t_list **list);
int		ft_add_str_list(t_list **list, char *str);
int		ft_count_str_size(t_list	**list);
char	*ft_trim_str(t_list **list);
void	ft_next_iterre(t_list **list);
void	ft_add_front(t_list **list, t_list **first);

#endif