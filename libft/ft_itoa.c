/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:01:13 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/30 02:38:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_numblen(long int enby)
{
	int	len;

	len = 0;
	if (enby < 0)
	{
		len++;
		enby *= -1;
	}
	else if (enby == 0)
		len++;
	while (enby > 0)
	{
		len++;
		enby /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*buffer;
	int			i;
	long int	enby;

	enby = (long int)n;
	i = ft_numblen(enby);
	buffer = malloc((i + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[i--] = '\0';
	if (enby < 0)
	{
		buffer[0] = '-';
		enby *= -1;
	}
	while (enby > 9)
	{
		buffer[i--] = enby % 10 + '0';
		enby /= 10;
	}
	buffer[i] = enby + '0';
	return (buffer);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	return (0);
// }
