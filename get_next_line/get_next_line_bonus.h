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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define MAX_FD 4096

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_stash(int fd, char *stash);
int		ft_isin(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract(char *str);
char	*ft_strclean(char *stash);
int		ft_strlen(char *str);

#endif