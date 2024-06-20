/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:46:16 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/13 18:46:16 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/basic_utils.h"

static void	*memjoin_free(const void *m1, size_t s1, const void *m2, size_t s2)
{
	void	*result;

	result = my_memjoin(m1, s1, m2, s2);
	free((void *)m1);
	return (result);
}

static void	extract_line(t_file_buffer *f)
{
	if (f->buffer == NULL || f->buff_len == 0)
	{
		f->len = 0;
		f->line = NULL;
		return ;
	}
	f->len = my_memchr_index(f->buffer, '\n', f->buff_len);
	if (f->len == -1)
	{
		f->line = my_memjoin(f->buffer, f->buff_len, "\0", 1);
		f->len = f->buff_len;
		f->buff_len = 0;
		free(f->buffer);
		f->buffer = NULL;
		return ;
	}
	f->line = my_memjoin(f->buffer, f->len + 1, "\0", 1);
	f->buff_len -= f->len + 1;
	my_memmove(f->buffer, f->buffer + f->len + 1, f->buff_len);
}

static int	read_until_end_line(int fd, t_file_buffer *f)
{
	char	*buffer;
	long	readed;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE);
	if (buffer == NULL)
		return (0);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			free(buffer);
			if (readed == 0 && f->buff_len == 0)
				free(f->buffer);
			return (readed == 0);
		}
		f->buffer = memjoin_free(f->buffer, f->buff_len, buffer, readed);
		f->buff_len += readed;
		if (my_memchr_index(f->buffer, '\n', f->buff_len) != -1)
		{
			free (buffer);
			return (1);
		}
	}
}

static char	*get_line(int fd, t_file_buffer *f)
{
	if (read_until_end_line(fd, f) == 0)
	{
		free (f->buffer);
		f->buff_len = 0;
		f->len = 0;
		return (NULL);
	}
	extract_line(f);
	return (f->line);
}

char	*get_next_line(int fd)
{
	static t_file_buffer	files[FOPEN_MAX] = {{NULL, 0, NULL, 0}};
	size_t					i;

	if (files[0].len == 0)
	{
		i = 1;
		while (i <= FOPEN_MAX)
		{
			files[i] = files[0];
			i ++;
		}
		files[0].len = 1;
	}
	if (fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	return (get_line(fd, &files[fd + 1]));
}
