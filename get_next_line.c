/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:02:21 by wzouf             #+#    #+#             */
/*   Updated: 2022/03/01 23:05:12 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line( char	**str, char	*line )
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, i + 1);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		*str = NULL;
		free (line);
		line = NULL;
	}
	if (!tmp[i])
		*str = NULL;
	if (tmp[i] == '\n')
		*str = ft_strdup(&tmp[i + 1]);
	free(tmp);
	return (line);
}

int	ft_norm(char *buf, char **str, int fd)
{
	if (!buf)
		return (1);
	if (!str[fd])
		str[fd] = ft_strdup("\0");
	if (!str[fd])
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*buffer;
	int			ret;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (ft_norm(buffer, str, fd))
		return (NULL);
	ret = 1;
	while (ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
		if (!str[fd])
			return (NULL);
		if (index_of(str[fd], '\n') != -1)
			break ;
	}
	return (free(buffer), get_line(&str[fd], line));
}
