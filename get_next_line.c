/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelman <abdelman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:12:31 by abdelman          #+#    #+#             */
/*   Updated: 2026/11/15 15:37:28 by abdelman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*get_line(char *ptr, int *ii)
{
	int		i;
	char	*s;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	*ii = i;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, ptr, i + 1);
	return (s);
}

int	read_fd(char **ptr, int fd, char **tmp)
{
	char	*new;
	int		n_readed;

	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (0);
	n_readed = 1;
	while (n_readed > 0 && ft_strchr(*ptr, '\n'))
	{
		n_readed = read(fd, new, BUFFER_SIZE);
		if (n_readed < 0)
			break ;
		new[n_readed] = '\0';
		*tmp = ft_strjoin(*ptr, new);
		free(*ptr);
		*ptr = *tmp;
		if (!*ptr)
			break ;
	}
	free(new);
	if (n_readed < 0 || !*ptr)
		ft_free(ptr);
	return (n_readed >= 0 && *ptr != NULL);
}

int	update_content(char **ptr, int i)
{
	char	*tmp;

	tmp = ft_strdup(*ptr + i);
	if (!tmp)
		return (0);
	free(*ptr);
	*ptr = tmp;
	return (1);
}

// char	*get_next_line(int fd)
// {
// 	static char	*ptr;
// 	char		*line;
// 	char		*tmp;
// 	int			i;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!read_fd(&ptr, fd, &tmp))
// 		return (NULL);
// 	if (!ptr || !*ptr)
// 		return (ft_free(&ptr));
// 	line = get_line(ptr, &i);
// 	if (!line)
// 		return (ft_free(&ptr));
// 	if (!update_content(&ptr, i))
// 	{
// 		free(line);
// 		return (ft_free(&ptr));
// 	}
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	*ptr[1024];
	char		*line;
	char		*tmp;
	int			i;

	if (read(fd,ptr[0],0) == (-1))
		return NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_fd(&ptr[fd], fd, &tmp))
		return (NULL);
	if (!ptr[fd] || !*ptr[fd])
		return (ft_free(&ptr[fd]));
	line = get_line(ptr[fd], &i);
	if (!line)
		return (ft_free(&ptr[fd]));
	if (!update_content(&ptr[fd], i))
	{
		free(line);
		return (ft_free(&ptr[fd]));
	}
	return (line);
}
