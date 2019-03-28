/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:00:10 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/03/19 16:23:13 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_line_starts(char **res, char **line, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (res[fd][len] != '\n' && res[fd][len] != '\0')
		len++;
	if (res[fd][len] == '\n')
	{
		*line = ft_strsub(res[fd], 0, len);
		tmp = ft_strdup(res[fd] + len + 1);
		free(res[fd]);
		res[fd] = tmp;
		if (res[fd][0] == '\0')
			ft_strdel(&res[fd]);
	}
	else if (res[fd][len] == '\0')
	{
		*line = ft_strdup(res[fd]);
		ft_strdel(&res[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			rd;
	char		buff[BUFF_SIZE + 1];
	static char	*res[4096];
	char		*tmp;

	if (fd < 0 || !line || fd > 4096)
		return (-1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (res[fd] == NULL)
			res[fd] = ft_strnew(1);
		tmp = ft_strjoin(res[fd], buff);
		free(res[fd]);
		res[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (rd < 0)
		return (-1);
	if (rd == 0 && res[fd] == '\0')
		return (0);
	return (ft_line_starts(res, line, fd));
}
