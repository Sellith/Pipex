/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:26:57 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/20 20:34:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_back(t_pids **lst, t_pids *new)
{
	t_pids	*tete;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tete = ft_lstlast(*lst);
	tete->next = new;
}

t_pids	*new(int content)
{
	t_pids	*dst;

	dst = malloc(sizeof(t_pids));
	if (dst == NULL)
		return (NULL);
	dst->pids = content;
	dst->next = NULL;
	return (dst);
}
