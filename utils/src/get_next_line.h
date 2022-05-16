/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:58:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/01 16:34:07 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_line_return(char **str, int i);
char	*gnl_no_read(char **str);
char	*gnl_buffer_not_empty(char **str, int i);
char	*gnl_read_loop(int fd, char **str);
void	*gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char **s1, char const *s2);
char	**gnl_substr(char **substr, char **s, unsigned int start, size_t len);
char	*gnl_strdup(char **s1, int istr);

#endif
