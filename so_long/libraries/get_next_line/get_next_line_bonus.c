/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:14:43 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/08/07 15:43:43 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new_line = (char *)ft_calloc((i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*new_line(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	new_line = ft_calloc((ft_strleng(line) - i + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		new_line[j++] = line[i++];
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*read_update(int fd, char *line)
{
	char	*buffer;
	int		cnt;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	cnt = 1;
	while (cnt != 0)
	{
		cnt = read(fd, buffer, BUFFER_SIZE);
		if (cnt < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[cnt] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoing(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line[fd])
		line[fd] = ft_strdup("");
	line[fd] = read_update(fd, line[fd]);
	if (line[fd] == NULL || line[fd][0] == '\0')
		return (free(line[fd]), line[fd] = NULL, NULL);
	rd = get_line(line[fd]);
	line[fd] = new_line(line[fd]);
	return (rd);
}

/* int main() {
    char *filename;
    char *line;
    int fd;

    // Test 1
    filename = "test.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 2
    filename = "test2.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
	
    return 0;
} */