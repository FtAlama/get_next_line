/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alama <alama@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:18:00 by alama             #+#    #+#             */
/*   Updated: 2024/05/26 15:56:39 by alama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;
	//char	*s;
	//char	*f;
	
	fd = open("text2.txt", O_RDONLY);
	//int	fq = open("test3.txt", O_RDONLY);
	//int	md = open("text.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(1);
		//s = get_next_line(fq);
		//f = get_next_line(md);
		if (str == NULL)
			break ;
		printf("%s", str);
		//printf("%s", s);
		//printf("%s", f);
		ft_free(&str);
		//ft_free(&s);
		//ft_free(&f);
	}
	close(fd);
	//close(fq);
	//close(md);
}
