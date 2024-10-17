/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:50:54 by mianni            #+#    #+#             */
/*   Updated: 2024/07/10 15:24:30 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_malloc_inside(const char *s1, const char *s2, int total)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	total = i + j + 1;
	return (total);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_read(int fd, char *buf, char *storage)
{
	int		len;
	char	*temp;

	len = 1;
	while (len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		else if (len == 0)
			break ;
		buf[len] = '\0';
		if (!storage)
			storage = ft_strdup("");
		if (!storage)
			return (NULL);
		temp = storage;
		storage = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (storage);
}

char	*ft_print_line(char *newline, char *storage)
{
	size_t	count;

	count = 0;
	while (newline[count] != '\n' && newline[count] != '\0')
		count++;
	if (newline[count] == '\0' || newline[1] == '\0')
		return (NULL);
	storage = ft_substr(newline, count + 1, ft_strlen(newline) - count);
	if (storage[0] == '\0' && storage && storage != NULL)
		return (free(storage), NULL);
	newline[count + 1] = '\0';
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*buf;
	char		*newline;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (BUFFER_SIZE <= 0 || fd < 0 || buf == NULL)
		return (free(buf), NULL);
	newline = ft_read(fd, buf, storage[fd]);
	if (!newline)
		return (free(buf), free(storage[fd]), storage[fd] = NULL, NULL);
	storage[fd] = ft_print_line(newline, storage[fd]);
	return (free(buf), newline);
}
