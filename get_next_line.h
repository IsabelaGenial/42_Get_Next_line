/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:32:29 by igenial           #+#    #+#             */
/*   Updated: 2023/06/14 19:32:33 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);


#endif
