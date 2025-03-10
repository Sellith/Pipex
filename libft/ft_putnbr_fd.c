/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:50:12 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/11/04 14:15:54 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	enby;

	enby = n;
	if (enby < 0)
	{
		ft_putchar_fd('-', fd);
		enby *= -1;
	}
	if (enby > 9)
		ft_putnbr_fd(enby / 10, fd);
	ft_putchar_fd(enby % 10 + '0', fd);
}
