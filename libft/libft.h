/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:57:04 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/25 16:57:07 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <stdarg.h>

# define BUFF_SIZE 1
# define DIFF(x, y) ((x > y) ? x - y : 0)
# define TEG(str, end) ((str[end] == 'x') ? "0x" : "0X")
# define CHECKM(a) ((a < 0) ? 4294967296 : 0)
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define B_RED "\x1b[31;1m"
# define B_GREEN "\x1b[32;1m"
# define B_YELLOW "\x1b[33;1m"
# define B_BLUE "\x1b[34;1m"
# define B_MAGENTA "\x1b[35;1m"
# define B_CYAN "\x1b[36;1m"
# define B_WHITE "\x1b[37;1m"
# define EOC "\x1b[0m"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_ret_value
{
	int			a;
	int			b;
}				t_ret_value;

typedef struct	s_num
{
	int			a;
	int			b;
	int			c;
}				t_num;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memalloc(size_t size);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *destination, const void *source, size_t n);

void			ft_memdel(void **ap);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putchar(char c);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl(char const *s);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr(int n);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr(char const *s);

void			ft_putstr_fd(char const *s, int fd);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strchr(const char *s, int c);

void			ft_strclr(char *s);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dst, const char *src);

void			ft_strdel(char **as);

char			*ft_strdup(const char *s1);

int				ft_strequ(char const *s1, char const *s2);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t			ft_strlen(const char *s);

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strncat(char *s1, const char *s2, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strncpy(char *dst, const char *src, size_t len);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strnew(size_t size);

char			*ft_strnstr(const char *haystack, const char *needle, size_t n);

char			*ft_strrchr(const char *s, int c);

char			**ft_strsplit(char const *s, char c);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strtrim(char const *s);

int				ft_tolower(int c);

int				ft_toupper(int c);

void			ft_lstadd(t_list **alst, t_list *new);

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list			*ft_lstnew(void const *content, size_t content_size);

int				get_next_line(const int fd, char **line);

int				get_every_line(int fd, int tmp, char **str, char **line);

char			*add_newline(char *s, int len);

int				ft_printf(const char *format, ...);

char			*parse_char(char c);

char			*address(long long int a);

char			*ft_itoa_base(long long int value, int base, char type);

char			*str_toupper(char *str);

char			*precision(int	start, int end, char *str, char *str2);

char			*prec_dioux(int num, char *str, char c, t_num count1);

char			*find_type(char type, va_list argptr, int tol);

int				precision_f(int	start, int end, char *str);

char			*ft_ftoa(long double n, int tol, int count);

char			*modifiers(int start, int end, char *str, va_list argptr);

char			*make_weigth(char *str, int start, int end, char *res);

int				str_s(char *str, int start, int end, char c);

char			*str_join_n(char *s1, char *s2);

void			replace(char **str, char *add, int i);

void			rreplace(char *str, char **add, int i);

int				mem(int a, char **str);

char			*colors(char *color);

char			*ft_utoa(unsigned long long n);

int				ft_atoi_base(char *str, int base);

#endif
