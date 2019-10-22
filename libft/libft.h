/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:20:45 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/03 22:20:46 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

# define BUFF_SIZE 64
# define RETRYMALLOC 10
# define ERR_MODE 0
# define LEAKS 0
# define LEAKS_STR "leaks -q lem-in >&2"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dc
{
	t_list			*branch;
	int				fd;
	struct s_dc		*next;
}					t_descriptor;

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_ishex(char ch);
int					ft_fittoint(const char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_capitalizer(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstsave(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_error(char *texterr, char *textdiag,
														int numerr, int mode);
size_t				ft_findchr(const char *s, int c, size_t n,
														unsigned char revers);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstpushend(t_list **alst, void *data, size_t size);
void				ft_contdel(void *content, size_t content_size);
void				ft_donothing(void *content, size_t content_size);
size_t				ft_lstcount(t_list *alst);
size_t				ft_lstsize(t_list *alst, size_t count);
t_list				*ft_lstcat(t_list **alst, size_t count,
							unsigned char del_mode, unsigned char next_mode);
t_list				*ft_lstterm(t_list *alst, unsigned char mode);
void				ft_elemnulterm(t_list *elem);
void				ft_elemnuldeterm(t_list *elem);
t_list				*ft_elemnewterm(t_list *elem);
t_list				*ft_elemnewdeterm(t_list *elem);
t_list				*ft_lstinter(t_list **alst, void *start, void *inter,
																	void *end);
size_t				ft_lstmaxsize(t_list *alst);
t_list				*ft_lstskip(t_list *elem, size_t count);
void				ft_lstaddafter(t_list *elem, t_list *new);
void				ft_lstdelcount(t_list **alst, size_t count);
t_list				*ft_split(char const *s, char delim, size_t counter);
void				ft_lstprint(t_list *lst, size_t count);
void				ft_lstrvr(t_list **alst);
char				**ft_lstarr(t_list **alst, int copy_mode, int del_mode);
t_list				*ft_arrlst(char ***arr, int copy_mode, int del_mode);
int					ft_qfree(char ***arr, t_list **alst);

int					get_next_line(const int fd, char **line);
char				*ft_itoa_base(long long nbr, int base, int sign,
																int precis);
int					ft_atoi_base(const char *str, int str_base);
void				*ed_memalloc(size_t size);
int					ft_onlyatoistr(char *line);

#endif
