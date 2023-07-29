/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenglee <chenglee@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:32:01 by chenglee          #+#    #+#             */
/*   Updated: 2023/05/28 11:32:02 by chenglee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_linked_lists.h"

// deletes a specific node from the linked list

void	freenode(t_list **head, t_list *node)
{
	t_list	*temp;
	t_list	*target;

	if (*head == node)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->stash);
		free(temp);
		return ;
	}
	temp = *head;
	while (temp->next)
	{
		if (temp->next == node)
		{
			target = temp->next;
			temp->next = target->next;
			free(target->stash);
			free(target);
			return ;
		}
		temp = temp->next;
	}
}

// adds a node to the back of the list and returns the pointer to that node

t_list	*backaddnode(int fd, char *stash, t_list **head)
{
	t_list	*temp;
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->fd = fd;
	new->stash = stash;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return (*head);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (temp->next);
}

// determines if a specific fd already exists in the linked list
// 1: 	if fd is found in the linked list, it will return that node.
// 2: 	if fd is not found in the linked list or there are not nodes, 
//		it will add a new node to the back and return the pointer to that node.

t_list	*getnode(int fd, t_list **head)
{
	t_list	*temp;
	char	*stash;

	temp = *head;
	while (temp)
	{
		if (fd == temp->fd)
			return (temp);
		temp = temp->next;
	}
	stash = malloc(sizeof(char));
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	temp = backaddnode(fd, stash, head);
	return (temp);
}

// fills up the stash with the file data read into the buffer.
// stops reading once a newline '\n' or EOF '\0' is reached. 
// If error is encountered, frees the local variable 'stash'
// and returns NULL;

char	*fill_stash(int fd, char *stash)
{
	int		bytes;
	char	*buff;
	char	*temp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = BUFFER_SIZE;
	while (stash && !ft_isin(stash, '\n') && bytes == BUFFER_SIZE)
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

// Gets the next line of the file by reading data from a 
// static variable 'stash' up to and including a newline '\n' 
// or EOF '\0'.
// If stash has not been initialized previously, mallocs and creates
// stash with an empty string.
// If result 'res' is an empty string or doesn't exists, returns NULL.

char	*get_next_line(int fd)
{
	static t_list	**stash_list;
	t_list			*curnode;
	char			*res;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stash_list)
	{
		stash_list = malloc(sizeof(t_list *));
		*stash_list = NULL;
	}
	curnode = getnode(fd, stash_list);
	curnode->stash = fill_stash(fd, curnode->stash);
	res = ft_extract(curnode->stash);
	curnode->stash = ft_strclean(curnode->stash);
	if (!res || !res[0])
	{
		free(res);
		freenode(stash_list, curnode);
		res = NULL;
	}
	return (res);
}
