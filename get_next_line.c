/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:32:38 by igenial           #+#    #+#             */
/*   Updated: 2023/06/14 21:53:50 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"

char	*ft_read(int fd, char *rest);
char	*ft_get_line(char *rest);
char	*ft_get_rest(char *temp_buffer);

char	*get_next_line(int fd)
{
	char 		*line;
	static char	*rest;

	rest = ft_read(fd, rest);
	line = ft_get_line(rest);
	rest = ft_get_rest(rest);
	return (line);
}

char	*ft_read(int fd, char *rest) 
{
	int 	bytes_read;
	char	*temp_buffer;

	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read || rest)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		free(rest);
		rest = ft_strjoin (rest, temp_buffer);
		if (ft_strchr(rest, '\n'))
			break ;
	}
	free(temp_buffer);
	return (rest);
}

char	*ft_get_line(char *temp_buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (temp_buffer[i] != '\n' && temp_buffer[i])
			i++;
	if (temp_buffer[i] == '\n')
		i++;
	line = ft_substr(temp_buffer, 0, i);
	return (line);
}

char	*ft_get_rest(char *temp_buffer)
{
	char	*buffer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (temp_buffer[i] != '\n' && temp_buffer[i])
			i++;
	if (!temp_buffer[i])
	{
		free(temp_buffer);
		return (NULL);
	}
	buffer = ft_calloc(((ft_strlen(temp_buffer) - i) + 1), sizeof(char));
	j = 0;
	while (temp_buffer[i] != '\0')
		buffer[j++] = temp_buffer[i++];
	free(temp_buffer);
	return (buffer);		
}
