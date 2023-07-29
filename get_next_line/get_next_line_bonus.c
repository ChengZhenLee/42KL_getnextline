/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenglee <chenglee@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:00:21 by chenglee          #+#    #+#             */
/*   Updated: 2023/05/27 13:00:22 by chenglee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_stash(int fd, char *stash)
{
	int		bytes;
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = BUFFER_SIZE;
	while (!ft_isin(stash, '\n') && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = ft_strjoin(stash, buff);
		free(stash);
		stash = temp;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stashes[MAX_FD];
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stashes[fd])
	{
		stashes[fd] = malloc(sizeof(char));
		stashes[fd][0] = '\0';;
	}
	stashes[fd] = fill_stash(fd, stashes[fd]);
	res = ft_extract(stashes[fd]);
	stashes[fd] = ft_strclean(stashes[fd]);
	if (!res || !res[0])
	{
		free(res);
		free(stashes[fd]);
		stashes[fd] = NULL;
		return (NULL);
	}
	return (res);
}
