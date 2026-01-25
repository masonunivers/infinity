/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:09:09 by jomason           #+#    #+#             */
/*   Updated: 2026/01/25 12:20:54 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_to_store(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}

char	*read_to_store(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*tmp;

	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		if (tmp)
			free(tmp);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash [i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		return (line[i] = stash[i], i++, line[i] = '\0', line);
	return (line[i] = '\0', line);
}

char	*clean_stash(char *stash)
{
	int		counter;
	int		rem_counter;
	char	*remainder;

	counter = 0;
	rem_counter = 0;
	while (stash[counter] != '\n' && stash[counter])
		counter++;
	if (!stash[counter])
		return (free(stash), NULL);
	counter++;
	if (stash[counter] == '\0')
		return (free(stash), NULL);
	remainder = malloc(ft_strlen(stash + counter) + 1);
	if (!remainder)
		return (free(stash), NULL);
	while (stash[counter + rem_counter] != '\0')
	{
		remainder[rem_counter] = stash[counter + rem_counter];
		rem_counter++;
	}
	remainder[rem_counter] = '\0';
	free(stash);
	return (remainder);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	int	fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (printf("I can't read o.o\n"), (fd < 0));
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
