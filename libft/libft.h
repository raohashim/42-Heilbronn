/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrao <mrao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 07:16:13 by mrao              #+#    #+#             */
/*   Updated: 2024/07/15 09:25:36 by mrao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t num_of_elements, size_t size_of_elements);
void	*ft_memchr(const void *s, int c, size_t n_bytes);
int		ft_memcmp(const void *str1, const void *str2, size_t n_bytes);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
int		ft_strncmp(const char *str1, const char *str2, size_t n_bytes);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(char c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *ptr, int value, size_t num);
void	*ft_bzero(void *ptr, unsigned int num);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putnbr_fd(int n, int fd);

#endif