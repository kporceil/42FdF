/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:36:56 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/10 16:35:29 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>

t_err		join_lst(t_buffer **lst, char **line);
t_buffer	*set_leftover(t_buffer *node);

char	*get_next_line(int fd, t_gnlmode mode)
{
	static t_buffer	*buffer_lst = NULL;
	t_err			err;
	char			*line;

	if (mode == DELETE)
		return (lst_clear(&buffer_lst));
	err = NO_ERR;
	while (is_line_complete(buffer_lst) == false && err == NO_ERR)
		err = lst_add(fd, &buffer_lst);
	if (err)
		return (lst_clear(&buffer_lst));
	err = join_lst(&buffer_lst, &line);
	if (err)
		return (lst_clear(&buffer_lst));
	return (line);
}

t_err	join_lst(t_buffer **lst, char **line)
{
	t_buffer	*node;
	ssize_t		len;
	ssize_t		i;
	ssize_t		j;

	node = *lst;
	len = ft_calc_len(node);
	if (len)
		*line = malloc(sizeof(char) * (len + 1));
	if (!len || !(*line))
		return (MALLOC_ERR);
	i = 0;
	while (node)
	{
		j = 0;
		while (j < node->bytes_read && node->buffer[j] != '\n' && i < len)
			(*line)[i++] = node->buffer[j++];
		if (j < node->bytes_read && node->buffer[j] == '\n')
			(*line)[i++] = node->buffer[j];
		node = node->next;
	}
	(*line)[i] = '\0';
	*lst = set_leftover(*lst);
	return (NO_ERR);
}

t_buffer	*set_leftover(t_buffer *node)
{
	ssize_t		i;
	ssize_t		j;
	t_buffer	*tmp;

	while (node && node->next)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	i = 0;
	while (i < node->bytes_read && node->buffer[i] != '\n')
		++i;
	++i;
	j = 0;
	while (i < node->bytes_read)
		node->buffer[j++] = node->buffer[i++];
	node->bytes_read = j;
	if (node->bytes_read == 0)
	{
		free(node);
		return (NULL);
	}
	return (node);
}
