/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:39:37 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 07:43:40 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdarray(char **darray)
{
	int	i;

	i = 0;
	while (darray[i] != NULL)
	{
		ft_putstr_fd(darray[i], 1);
		i++;
	}
}
