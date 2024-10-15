/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeleimat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:44:50 by aeleimat          #+#    #+#             */
/*   Updated: 2024/09/18 12:44:53 by aeleimat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(save);
		return (NULL);
	}
	byte_read = 1;
	while (!check_for_newline(save) && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

static char	*cut_a_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*cut_the_line(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(save) - i + 1);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	i++;
	j = 0;
	while (save[i] != '\0')
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = cut_a_line(save);
	save = cut_the_line(save);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
        int             fd;
        char    *line;

        fd = open("abd.txt", O_RDWR);
        if (fd < 0)
        {
                perror("Error opening file");
                return (1);
        }
		line = get_next_line(fd);
			printf("%s", line);
        while ((line = get_next_line(fd)) != NULL)
        {
                printf("%s", line);
                free(line);
        }
        close(fd);
        return (0);
 }
*/
