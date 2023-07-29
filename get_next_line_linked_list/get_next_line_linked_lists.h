/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenglee <chenglee@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:00:33 by chenglee          #+#    #+#             */
/*   Updated: 2023/05/27 13:00:34 by chenglee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_LINKED_LISTS_H
# define GET_NEXT_LINE_LINKED_LISTS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*fill_stash(int fd, char *stash);
int		ft_isin(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract(char *str);
char	*ft_strclean(char *stash);
int		ft_strlen(char *str);
void	freenode(t_list **head, t_list *node);
t_list	*backaddnode(int fd, char *stash, t_list **head);
t_list	*getnode(int fd, t_list **head);

#endif