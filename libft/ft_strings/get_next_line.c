/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 04:51:40 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:43:41 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static t_line		*ft_search_or_create(t_line **list, const int fd)
{
	t_line			*elem;

	elem = *list;
	while (elem)
	{
		if (elem->fd == fd)
			return (elem);
		elem = elem->next;
	}
	if (!(elem = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	elem->fd = fd;
	elem->save = NULL;
	elem->next = *list;
	*list = elem;
	return (elem);
}

static char			*ft_find_and_store(t_line *curr, char buff[BUFF_SIZE + 1])
{
	char			*tmp;
	char			*sub;
	char			*nlc;
	char			*str;
	size_t			size;

	str = ft_strnew(0);
	while (!(nlc = ft_strchr(buff, '\n')))
	{
		SWAP_FREE(tmp, str, ft_strjoin(str, buff));
		if (!(size = read(curr->fd, buff, BUFF_SIZE)))
		{
			ft_strdel(&(curr->save));
			return (str);
		}
		buff[size] = '\0';
	}
	sub = ft_strsub(buff, 0, (nlc - buff));
	SWAP_FREE(tmp, str, ft_strjoin(str, sub));
	free(sub);
	SWAP_FREE(tmp, curr->save,
			ft_strsub(buff, (nlc - buff) + 1, BUFF_SIZE + (nlc - buff)));
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	*list = NULL;
	t_line			*curr;
	char			buff[BUFF_SIZE + 1];
	size_t			size;

	if (fd < 0 || read(fd, NULL, 0) == -1 || !line || BUFF_SIZE < 1)
		return (-1);
	curr = ft_search_or_create(&list, fd);
	if (curr->save && ft_strlen(curr->save))
		ft_strcpy(buff, curr->save);
	else
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
			return (0);
		buff[size] = '\0';
	}
	*line = ft_find_and_store(curr, buff);
	return (1);
}
