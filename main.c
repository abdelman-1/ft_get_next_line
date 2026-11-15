
#include "get_next_line.h"

// size_t ft_strlen(const char *s)
// {
// 	size_t i;

// 	i = 0;
// 	while (s && s[i])
// 		i++;
// 	return (i);
// }

// size_t ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t i;

// 	if (size == 0)
// 		return (ft_strlen(src));
// 	i = 0;
// 	while (src[i] && i < size - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (ft_strlen(src));
// }

// char *ft_strdup(const char *s)
// {
// 	size_t i;
// 	char *ptr;

// 	if (!s)
// 		return (NULL);
// 	ptr = malloc(ft_strlen(s) + 1);
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		ptr[i] = s[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// char *ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t len1;
// 	size_t len2;
// 	char *ptr;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	ptr = malloc(len1 + len2 + 1);
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, s1, len1 + 1);
// 	ft_strlcpy(ptr + len1, s2, len2 + 1);
// 	return (ptr);
// }

// int ft_strchr(const char *s, int c)
// {
// 	size_t i;
// 	unsigned char st;

// 	if (!s)
// 		return (1);
// 	st = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((unsigned char)s[i] == st)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }







// char *read_line(char *line , char *ptr)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (ptr[i] && ptr[i] != '\n')
// 		i++;
// 	if (ptr[i] == '\n')
// 		i++;
// 	line = malloc(i + 1);
// 	j = 0;
// 	while (j < i)
// 		line[j] = ptr[j];
// 	line[j] = '\0';
// 	return (strdup(ptr + i));
// }


// char *get_line(char *ptr,int *ii)
// {
// 	int	i;
// 	int	j;
// 	char *s;

// 	i = 0;
// 	while (ptr[i] && ptr[i] != '\n')
// 	i++;
// 	if (ptr[i] == '\n')
// 		i++;
// 	*ii = i;
// 	s = malloc(i + 1);
// 	if (!s)
// 		return (NULL);
// 	j = 0;
// 	while (j < i)
// 	{
// 		s[j] = ptr[j];
// 		j++;
// 	}
	
// 	s[j] = '\0';
// 	return (s);
// }

// void read_fd(char **ptr,int *n_readed, int fd, char **tmp )
// {
// 	char *new;

// 	new = malloc(BUFFER_SIZE + 1);
// 	if (!new)
// 		return ;
// 	while (*n_readed > 0 && ft_strchr(*ptr,'\n'))
// 	{
// 		*n_readed = read(fd,new,BUFFER_SIZE);
// 		if (*n_readed < 0)
// 		{
// 			free(new);
// 			return ;
// 		}
// 		new[*n_readed] = 0;
// 		*tmp = ft_strjoin(*ptr,new);
// 		if (!(*tmp))
// 		{
// 			free(*ptr);
// 			free(new);
// 			return ;
// 		}
// 		free(*ptr);
// 		*ptr = *tmp;
// 	}
// 	free(new);
// }

// char *get_next_line(int fd)
// {
// 	static char *ptr;
// 	char *line;
// 	int	n_readed;
// 	char *tmp;
// 	int i;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	n_readed = 1;
// 	i = 0;
// 	read_fd(&ptr,&n_readed,fd,&tmp);
// 		if (!ptr || !*ptr)
// 		return (NULL);
// 	line = get_line(ptr,&i);
// 	tmp = ft_strdup(ptr + i);
// 	free(ptr);
// 	ptr = tmp;
// 	return (line);
// }

#include <stdio.h>
// int main(void)
// {
// 	// int i = 0;
// 	char *s ;
// 	// s = &i;
// 	int fd = open("test.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s\n",s);//AZIZ
// 	free(s);
// 	fd = open("testt.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s\n",s);//XXX
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s\n",s);//MN
// 	free(s);
// 	close(fd);
// 	close(3);
// }

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// int main(void)
// {
//     char *s;
// 	int fd = open("test.txt", O_RDONLY);
//     s = get_next_line(fd);
//     printf("%s\n",s);
//     free(s);
//     close(fd);
// 	s = get_next_line(fd);
//     printf("%s\n",s);
//     return (0);
// }

// int main()
// {
// 	int fd[2];
// 	pipe(fd);
// 	write(fd[1], “hello\nworld\n”, 12);
// 	close (fd[1]);
// 	char *s = get_next_line(fd[0]);
// 	printf("%s",s);
// 	free(s);
// 	s = get_next_line(fd[0]);
// 	printf("%s",s);
// 	free(s);
// }




#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    int count;

    count = 0;
    while (1)
    {
        fd = open("/dev/null", O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            break;
        }
        printf("FD: %d\n", fd);
        count++;
    }
    printf("\nTotal opened files: %d\n", count);
    return (0);
}


