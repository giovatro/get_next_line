/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:05:18 by gtroiano          #+#    #+#             */
/*   Updated: 2023/08/28 11:04:48 by gtroiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *line)
{
	char	*after_n;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	after_n = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*after_n == '\0')
	{
		free(after_n);
		after_n = NULL;
	}
	line[i + 1] = '\0';
	return (after_n);
}

static char	*ft_find_line(int fd, char *buffer, char *stash)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (stash != NULL)
				free(stash);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_find_line(fd, buffer, stash);
	free(buffer);
	if (!line) 
	{
		if (stash != NULL)
			stash = NULL;
		return (NULL);
	}
	stash = ft_extract_line(line);
	return (line);
}
