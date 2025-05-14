/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:20:26 by erantala          #+#    #+#             */
/*   Updated: 2025/05/12 18:59:34 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

void	ft_bzero(void *str, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_printhex_fd(unsigned long int n, int fd, char type, int mem);
int		ft_printchar_fd(char c, int fd);
int		ft_printmem_fd(void	*p, int fd);
int		ft_printnbr_fd(int n, int fd);
int		ft_printstr_fd(char *s, int fd);
int		ft_printf(const char *s, ...);
int		ft_printunbr_fd(unsigned int n, int fd);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
char	*get_next_line(int fd);
char	*line_strchr(const char *s, int c);
size_t	trim_length(char *buffer);
size_t	line_strlen(const char *s);
char	*get_buffer(int fd, int bff_size, char *line, int *status);
char	*trim_buffer(char *buffer, int line_status);
char	*line_strjoin(char const *s1, char const *s2);
char	*line_move(char *dest, const char *src, size_t n);
void	line_trim(char *line);
void	*line_memset(void *s, int c, size_t n);
void	ft_frearr(void **s, int lines);
char	**ft_stradup(char **src);
char	*ft_stradd(char const *s1, char const *s2);
size_t	ft_stralen(char **s);

#endif