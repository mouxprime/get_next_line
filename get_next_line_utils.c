/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:51:06 by mianni            #+#    #+#             */
/*   Updated: 2024/07/04 18:21:42 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		total;
	int		i;
	int		j;

	total = 0;
	total = ft_malloc_inside(s1, s2, total);
	dest = malloc(total * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	unsigned long int	j;

	j = 0;
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[start + j] && j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;
	char	*sbis;

	sbis = (char *)(s);
	i = 1 + ft_strlen(sbis);
	dest = malloc(i * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t i)
{
	unsigned long int	j;
	char				*char_ptr;

	j = 0;
	char_ptr = (char *)s;
	while (j < i)
	{
		char_ptr[j] = '\0';
		j++;
	}
}
