/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:17:41 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/30 17:44:26 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_size(int c, char *save)
{
	int	i;

	i = 0;
	while (save[i] && save[i] != c)
		i++;
	if (save[i] == c)
		return (i);
	return (-1);
}

void	get_sub_save(int start, char *save)
{
	int		i;
	int		size;
	char	*temp;

	size = ft_strlen(save);
	i = 0;
	while (save[i] && start--)
		i++;
	temp = ft_strndup(save + i + 1, size);
	ft_strncpy(save, temp, size);
	free(temp);
}

int		get_file(int fd, char *save)
{
	int	readfile;

	if (read(fd, &readfile, 0) == -1)
		return (0);
	readfile = 1;
	if (!save[0])
		ft_bzero(save, STACK_SIZE + BUFFER_SIZE);
	while (readfile > 0 && get_size('\n', save) == -1)
		readfile = read(fd, &save[ft_strlen(save)], BUFFER_SIZE);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	save[STACK_SIZE + BUFFER_SIZE];
	int			size;
	int			ret;
	char		*dest;

	ret = 1;
	if (!get_file(fd, save) || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if ((size = get_size('\n', save)) == -1)
	{
		size = ft_strlen(save);
		ret = 0;
	}
	if (save[0])
		dest = ft_strndup(save, size);
	else
	{
		if (!(dest = malloc(1)))
			return (-1);
		dest[0] = '\0';
	}
	get_sub_save(size, save);
	*line = dest;
	return (ret);
}
