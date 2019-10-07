/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 08:32:30 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:32:58 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>

typedef struct							s_list
{
	void								*content;
	size_t								content_size;
	struct s_list						*next;
}										t_list;

typedef struct							s_printf
{
	char								flag[5];
	int									field;
	int									pres;
	enum	{no, hh, h, l, ll, j, z, L}	num;
}										t_printf;

int										ft_printf(const char *format, ...);
int										ft_numlen(intmax_t d);
int										ft_field(int i, t_printf **list,
										const char *format);
void									putn(int n, char c);
int										ft_switch(const char *format,
										va_list ap, t_printf *list, int i);
int										ft_printf(const char *format, ...);
int										ft_char(char c, t_printf *list);
int										ft_str(char *s, t_printf *list);
int										ft_num(intmax_t d, t_printf *list);
int										ft_octal(uintmax_t d, t_printf *list);
int										ft_hex(uintmax_t d, t_printf *list,
										int a);
int										ft_uns(uintmax_t d, t_printf *list);
int										ft_point(uintmax_t d, t_printf *list);
int										ft_float(double d, t_printf *list);
int										ft_numlent(uintmax_t d);
int										ft_numlend(double d);
int										length1(va_list ap, t_printf *list);
int										length2(va_list ap, t_printf *list);
int										length3(va_list ap, t_printf *list);
int										length4(va_list ap, t_printf *list);
int										length5(va_list ap, t_printf *list);
int										ft_numlenx(uintmax_t d, int a);
void									ft_clean(t_printf **list);
char									*ft_oct(uintmax_t d);
int										ft_pf(t_printf **list,
										const char *format, va_list ap);
int										ft_format(const char *format, int i,
										t_printf **list);
char									*ft_numm(intmax_t d);
void									ft_bl(t_printf *list, intmax_t d,
										int n, char *s);
char									*convfloat(double d, t_printf *list);
int										ft_check(char c);
int										ft_modif(const char *format, int i,
										t_printf **list);
int										ft_pres(const char *format, int i,
										t_printf **list);
char									*ft_hexx(uintmax_t d, int a);
void									strn(int l, char *s);
int										ft_octal1(t_printf *list);
int										ft_no(t_printf *list, int a,
										uintmax_t d);
int										ft_nx(t_printf *list, int a,
										uintmax_t d);
int										ft_nu(t_printf *list, int a);
int										ft_nd(t_printf *list, int a,
										intmax_t d);
int										ft_lx(t_printf *list, int n,
										int a, int d);
void									ft_hash(t_printf *list, int a,
										uintmax_t d);
int										ft_lo(t_printf *list, int n,
										int a, int d);
int										ft_num1(t_printf *list);
void									ft_num2(t_printf *list,
										intmax_t d, char *s);
void									ft_num3(t_printf *list,
										char *s, intmax_t d, int n);
int										ft_nf(t_printf *list, int a, double d);
int										ft_nf1(t_printf *list, int a,
										unsigned long long *x, double d);
int										ft_ns(t_printf *list, int a);
void									ft_str0(t_printf *list);
int										ft_float1(t_printf *list, double d,
										int n, char *s);
int										ft_float2(t_printf *list,
										unsigned long long *x);
void									ft_float4(t_printf *list,
										unsigned long long *x, char *s);
void									*ft_memset(void *s, int c, size_t n);
void									ft_bzero(void *s, size_t n);
void									*ft_memcpy(void *s2, const void *s1,
										size_t n);
void									*ft_memccpy(void *s2, const void *s1,
										int c, size_t n);
void									*ft_memmove(void *s2, const void *s1,
										size_t n);
void									*ft_memchr(const void *s, int c,
										size_t n);
int										ft_memcmp (const void *s1,
										const void *s2, size_t n);
size_t									ft_strlen(const char *str);
char									*ft_strdup(const char *src);
char									*ft_strcpy(char *s2, const char *s1);
char									*ft_strncpy (char *s2, const char *s1,
										size_t l);
char									*ft_strcat (char *s2, const char *s1);
char									*ft_strncat (char *s2, const char *s1,
										size_t n);
size_t									ft_strlcat (char *s2, const char *s1,
										size_t l);
char									*ft_strchr (const char *str, int ch);
char									*ft_strrchr (const char *str, int ch);
char									*ft_strstr(const char *s1,
										const char *s2);
char									*ft_strnstr(const char *s1,
										const char *s2,
										size_t n);
int										ft_strcmp(const char *s1,
										const char *s2);
int										ft_strncmp(const char *s1,
										const char *s2,
										size_t n);
int										ft_atoi(const char *str);
int										ft_isalpha(int ch);
int										ft_isdigit(int ch);
int										ft_isascii(int ch);
int										ft_isalnum(int ch);
int										ft_isprint(int ch);
int										ft_tolower(int ch);
int										ft_toupper(int ch);
void									*ft_memalloc(size_t
										size);
void									ft_memdel(void **ap);
char									*ft_strnew(size_t size);
char									*ft_strdel(char **as);
void									ft_strclr(char *s);
void									ft_striter(char *s,
										void (*f)(char *));
void									ft_striteri(char *s,
										void (*f)(unsigned int, char *));
char									*ft_strmap(char const *s,
										char (*f)(char));
char									*ft_strmapi(char const *s,
										char (*f)(unsigned int, char));
int										ft_strequ(char const *s1,
										char const *s2);
int										ft_strnequ(char const *s1,
										char const *s2, size_t n);
char									*ft_strsub(char const *s,
										unsigned int start, size_t len);
char									*ft_strjoin(char const *s1,
										char const *s2);
char									*ft_strtrim(char const *s);
char									**ft_strsplit(char const *s, char c);
char									*ft_itoa(int n);
void									ft_putchar(char c);
void									ft_putstr(char const *s);
void									ft_putendl(char const *s);
void									ft_putnbr(int n);
void									ft_putchar_fd(char c, int fd);
void									ft_putstr_fd(char const *s, int fd);
void									ft_putendl_fd(char const *s, int fd);
void									ft_putnbr_fd(int n, int fd);
t_list									*ft_lstnew(void const *content,
										size_t content_size);
void									ft_lstdelone(t_list **alst,
										void (*del)(void *, size_t));
void									ft_lstdel(t_list **alst,
										void (*del)(void *, size_t));
void									ft_lstadd(t_list **alst, t_list *new);
void									ft_lstiter(t_list *lst,
										void (*f)(t_list *elem));
t_list									*ft_lstmap(t_list *lst,
										t_list *(*f)(t_list *elem));
int										ft_sqr(int n);
int										ft_sqrt(int n);
int										ft_fact(int n);
int										ft_prime(int n);
int										ft_abs(int n);
int										ft_words(char const *s, char c, int n);
void									ft_setline(void *s1, void *s2);
char									*ft_strndup(const char *src, int n);

#endif
