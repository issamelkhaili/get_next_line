/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 03:35:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/06 08:30:14 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define	BUFFER_SIZE 5

static char	*ft_read_file(int fd, char	*stash)
{
	char	*buffer;
	int 	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*ft_extract_line(char	*stash)
{
	char	*line;
	int		i;

	if(!stash)
		return (NULL);
	i = 0;
	while(stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(i + 2);
	if(!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if	(stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static	char	*ft_upate_stash(char	*stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	if(!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	while (stash[i + j])
		j++;
	if (stash[i] == '\n')
		i++;
	new_stash = malloc(j + 1);
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char *get_next_line(int fd)
{
	static	char	*leftover;
	if (fd > 0)
		reuturn (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);


}

