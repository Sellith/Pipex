/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:54:48 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/03 00:48:46 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	dst = malloc(sizeof(t_list));
	if (dst == NULL)
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}

// #include <stdio.h>

// void	ft_lstprint(t_list *liste)
// {
// 	t_list	*tmp;

// 	tmp = liste;
// 	while (tmp != NULL)
// 	{
// 		printf("%s -> ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		ft_lstprint(ft_lstnew(ft_strdup(argv[1])));
// 	}
// 	return (0);
// }
