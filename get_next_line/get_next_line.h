/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:41:15 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/30 17:46:01 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# ifndef STACK_SIZE
#  define STACK_SIZE 30000
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strncpy(char *dest, char *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		get_next_line(int fd, char **line);

#endif
