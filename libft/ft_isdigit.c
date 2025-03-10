/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:06:03 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 06:14:36 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main(void)
// {
// 	int	ch = 'a';

// 	printf("le resultat de ma fonction est %d\n", ft_isdigit(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isdigit(ch));
// 	return (0);
// }
