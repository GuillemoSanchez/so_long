/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiller <guiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:03:25 by guisanch          #+#    #+#             */
/*   Updated: 2023/10/26 17:06:47 by guiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
size_t	ft_strlen(char const *word);
void	*ft_memchr(const void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int carac);
int		ft_isalpha(int letter);
int		ft_isascii(int c);
int		ft_isdigit(int digit);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(const char *word, int pos);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
char	*ft_strrchr(const char *word, int pos);
int		ft_tolower(int letter);
int		ft_toupper(int letter);
void	*ft_memcpy(void *dst, const void *str, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strchr_gnl(const char *word, char chr);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*read_to_stash(int fd, char *stash);
char	*ft_new_stash(char *stash);
char	*ft_get_line(char *stash);
char	*get_next_line(int fd);
# endif
#endif