/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:16:02 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 06:12:21 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main(void)
// {
// 	int	ch = '0';

// 	printf("le resultat de ma fonction est %d\n", ft_isalnum(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isalnum(ch));
// 	return (0);
// }
