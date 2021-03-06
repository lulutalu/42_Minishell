/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo && lzima				            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:20:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/07/05 12:26:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "utils.h"
# include "minishell.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>

/*
 * Libft Functions
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	*ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_dyn_substr(char **s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_dyn_strjoin(char *dynstr, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	*ft_itoa_base(char **res, unsigned long n, char const *base);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
int		ft_putchar_fd_count(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr_fd_count(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_fd_count(long n, int fd, int *count);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del) (void *));
void	ft_lstclear(t_list **lst, void (*del) (void *));
void	ft_lstiter(t_list *lst, void (*f) (void *));
t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *));
void	ft_mem_alloc_check(void *ptr);
void	ft_tab_free(void **ptr);
int		ft_strcmp_case(const char *s1, const char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*gnl_line_return(char **str, int i);
char	*gnl_no_read(char **str);
char	*gnl_buffer_not_empty(char **str, int i);
char	*gnl_read_loop(int fd, char **str);
char	*get_next_line(int fd);

void	*gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char **s1, char const *s2);
char	*gnl_strdup(char **s1, int istr);
char	**gnl_substr(char **substr, char **s, unsigned int start, size_t len);

#endif
