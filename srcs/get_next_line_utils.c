/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:31:24 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/10 16:17:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_err	lst_add(int fd, t_buffer **lst)
{
	t_buffer	*lst_last;
	t_buffer	*new;

	new = malloc(sizeof(t_buffer));
	if (!new)
		return (MALLOC_ERR);
	new->next = NULL;
	new->bytes_read = read(fd, new->buffer, BUFFER_SIZE);
	if (!(*lst))
		*lst = new;
	else
	{
		lst_last = *lst;
		while (lst_last->next)
			lst_last = lst_last->next;
		lst_last->next = new;
	}
	if (new->bytes_read < 0)
		return (READ_ERR);
	return (NO_ERR);
}

bool	is_line_complete(t_buffer *buffer)
{
	ssize_t	i;

	i = 0;
	if (!buffer)
		return (false);
	while (buffer->next)
		buffer = buffer->next;
	if (buffer->bytes_read == 0)
		return (true);
	while (i < buffer->bytes_read)
	{
		if (buffer->buffer[i] == '\n')
			return (true);
		++i;
	}
	return (false);
}

void	*lst_clear(t_buffer **lst)
{
	t_buffer	*tmp;
	t_buffer	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	*lst = NULL;
	return (NULL);
}

ssize_t	ft_calc_len(t_buffer *lst)
{
	ssize_t	len;
	ssize_t	i;

	len = 0;
	while (lst->next)
	{
		len += lst->bytes_read;
		lst = lst->next;
	}
	i = 0;
	while (i < lst->bytes_read && lst->buffer[i] != '\n')
		++i;
	if (i != lst->bytes_read)
		++i;
	return (len + i);
}
