/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:15:10 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/08 18:20:04 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*freenull(char *tofree)
{
	free(tofree);
	return (NULL);
}

char	*ft_read_line(int fd, char *store)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + (size_t)1);
	if (!buffer)
		return (freenull(store));
	bytes_read = 1;
	while (!ft_strchr(store, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (freenull(store));
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		store = ft_strjoin(store, buffer);
		if (!store)
			return (freenull(store));
	}
	free(buffer);
	return (store);
}

char	*ft_extract_line(char *store)
{
	char	*line;
	long	i;

	i = 0;
	if (!store || store[0] == '\0')
		return (NULL);
	while (store[i] != '\n' && store[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] != '\n' && store[i] != '\0')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_store(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	new_store = malloc(ft_strlen(store) - i);
	if (!new_store)
		return (freenull(store));
	i++;
	j = 0;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = '\0';
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	static char	*store[MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	store[fd] = ft_read_line(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = ft_extract_line(store[fd]);
	store[fd] = ft_update_store(store[fd]);
	return (line);
}
