/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:54:49 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/12 20:37:16 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# define PROTECT(x) if (!x) return (NULL);
# define PROTECT_GNL(z) if (z) return (-1);
# define GENERAL_PROT(y) if (y) return (0);

int				ft_strstartswith(char *s1, char *s2);
void			ft_strclr(char *s);
int				ft_intlen(int c);
int				ft_atoi(const char *c);
int				ft_isspace(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strstr(const char *hastack, const char *needle);
char			*ft_strnstr(const char *hay, const char *ndl, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *restrict d, const void *restrict s, size_t n);
void			ft_memdel(void **ap);
char			*ft_strdup(const char *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			fit_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_intlen(int n);
char			**ft_strsplit(char const *s, char c);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dst, char const *src, size_t len);
char			*ft_itoa(int n);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strrchr(char const *s, int c);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strchr(char const *s, int c);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isalnum(int c);
char			*ft_itoa(int n);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstpushback(t_list **list, void *cont, size_t cont_size);

#endif
