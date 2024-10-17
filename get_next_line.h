/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:51:13 by mianni            #+#    #+#             */
/*   Updated: 2024/07/04 18:19:07 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char			*get_next_line(int fd);

char			*ft_read(int fd, char *buf, char *storage);

int				ft_check(char *buf);

unsigned int	ft_strlen(const char *str);

char			*ft_strjoin(const char *s1, const char *s2);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strchr(const char *s, int i);

int				ft_malloc_inside(const char *s1, const char *s2, int total);

// int				main(void);

void			ft_bzero(void *s, size_t i);

char			*ft_strdup(const char *s);

#endif
