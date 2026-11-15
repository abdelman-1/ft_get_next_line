/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelman <abdelman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:07:39 by abdelman          #+#    #+#             */
/*   Updated: 2026/11/15 13:15:38 by abdelman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
int ft_strchr(const char *s, int c);
char *read_line(char *line , char *ptr);
char *get_line(char *ptr,int *ii);
int	read_fd(char **ptr, int fd, char **tmp);
char *get_next_line(int fd);

#endif