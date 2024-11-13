/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:58:58 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/08/07 15:45:15 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_line(char *line);
char	*newline(char *line);
char	*read_update(int fd, char *buffer);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoing(char *s1, char *s2);
int		ft_strleng(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif