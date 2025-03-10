/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:48:56 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 09:57:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlarray(long *larray, int args)
{
	int	i;

	i = 0;
	printf("%i", args);
	while (i < args)
	{
		ft_putnbr_fd(larray[i], 1);
		write(1, "\n", 1);
		i++;
	}
}
