/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayun <jayun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:05:15 by jayun             #+#    #+#             */
/*   Updated: 2021/03/14 02:05:17 by jayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_save(char **save, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	if ((*save) != 0)
	{
		while ((*save)[i] != '\0' && (*save)[i] != '\n')
			i++;
		if ((*save)[i] != '\n')
			return (0);
		*line = ft_strdup_size(*save, 0, i);
		if (*line == 0)
		{
			free(*save);
			return (-1);
		}
		temp = ft_strdup_size(*save, i + 1, ft_strlen(*save));
		free(*save);
		if (temp == 0)
			return (-1);
		*save = temp;
		return (1);
	}
	return (0);
}

static int	save_plus_buf(char **save, char *buf, int n)
{
	char	*temp;

	if (*save != 0)
	{
		temp = ft_strjoin(*save, buf);
		free(*save);
		if (temp == 0)
			return (-1);
		*save = temp;
	}
	else
	{
		*save = ft_strdup_size(buf, 0, n);
		if (*save == 0)
			return (-1);
	}
	return (0);
}

static int	read_line(int fd, char **line, char **save)
{
	int		n;
	int		m;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (1 + 1));
	if (buf == 0)
		return (-1);
	n = read(fd, buf, 1);
	while (n > 0)
	{
		buf[n] = '\0';
		m = save_plus_buf(&(*save), buf, n);
		if (m != -1)
			m = find_save(&(*save), &(*line));
		if (m != 0)
		{
			free(buf);
			return (m);
		}
		n = read(fd, buf, 1);
	}
	free(buf);
	return (n);
}

static int	rest_clear(char **save, char **line)
{
	if (*save != 0)
	{
		*line = ft_strjoin("", *save);
		if (*line == 0)
		{
			free(*save);
			*save = NULL;
			return (-1);
		}
	}
	else if (*save == 0)
	{
		*line = (char *)malloc(sizeof(char));
		if (*line == 0)
			return (-1);
		(*line)[0] = '\0';
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			n;
	static char	*save[10240];

	if (fd < 0 || line == 0)
		return (-1);
	if (save[fd] != 0)
	{
		n = find_save(&save[fd], &(*line));
		if (n != 0)
			return (n);
	}
	n = read_line(fd, &(*line), &save[fd]);
	if (n == 1)
		return (1);
	if (n == 0)
		n = rest_clear(&save[fd], &(*line));
	if (save[fd] != 0)
		free(save[fd]);
	save[fd] = NULL;
	return (n);
}
