/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:01:13 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/19 01:04:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int main(void)
// {
// 	int	ch = 0;

// 	printf("le resultat de ma fonction est %d\n", ft_isascii(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isascii(ch));
// 	return (0);
// }
