/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:45:24 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/16 15:45:26 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef FD_MAX
#  define FD_MAX 512
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_split
{
	int		i;
	int		n_words;
	int		index;
	int		start;
	char	**dest;
}	t_split;

typedef struct s_format
{
	int		left_just;
	int		zero_pad;
	int		width;
	int		precision;
	int		precision_set;
	char	specifier;
	int		space;
	int		sign;
	int		hash;
}	t_format;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_is_incset(char ch, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nmemb, size_t size);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putstr_var_fd(char *s, int start, int end, int fd);
int		ft_abs(int n);

/* Get Next line functions */
char	*get_next_line(int fd);
char	*new_line(char *buffer);
char	*read_line(char *buffer);
char	*read_buffer(int fd, char *buffer);

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* ft_print_c.c */
int		ft_print_c(char c, t_format *spec);

/* ft_print_s.c */
int		ft_print_s(char *str, t_format *spec);

/* ft_print_p.c */
int		ft_print_p(void *str, t_format *spec);

/* ft_print_int.c */
int		int_bonus_flags(t_format *spec);
int		ft_print_int(int nbr, t_format *spec);
void	ft_print_int_aux(size_t nbr, t_format *spec, int c_nbr, int *c_total);

/* ft_print_u.c */
int		ft_print_u(unsigned int nbr, t_format *spec);

/* ft_print_x.c */
int		ft_print_x(unsigned int nbr, t_format *spec);
int		x_bonus_flags(t_format *spec, unsigned int nbr, char option);

/* ft_print_X.c */
int		ft_print_bigx(unsigned int nbr, t_format *spec);

/* ft_atoi_simple.c */
int		ft_atoi_simple(const char *nptr, int *i);
int		add_flg(const char *str, int *i, t_format *format, va_list *ap);

/* ft_print_width.c */
int		big(int i1, int i2);
void	print_filler(int *i, t_format *a);
int		ft_print_width_left(int size, t_format *spec);
int		ft_print_width_right(int size, t_format *spec);
int		ft_print_prec(int size, t_format *spec);

/* ft_print_width_cs.c */
int		ft_print_width_left_cs(int size, t_format *a);
int		ft_print_width_right_cs(int size, t_format *spec);

void	ft_putunsnbr_fd(unsigned int n, int fd);
int		add_flg_aux_1(const char *str, int *i, t_format *format);
int		add_flg_aux_2(const char *str, int *i, t_format *format, va_list *ap);

/* ft_flags.c */
void	*ft_print_func(t_format *spec);
int		add_flg_aux_1(const char *str, int *i, t_format *format);
int		add_flg_aux_2(const char *str, int *i, t_format *format, va_list *ap);
int		add_flg(const char *str, int *i, t_format *format, va_list *ap);

#endif
