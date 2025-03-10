/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:10:01 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/01/31 06:12:14 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// int main(void)
// {
// 	int	ch = '1';

// 	printf("le resultat de ma fonction est %d\n", ft_isalpha(ch));
// 	printf("le resultat de la fonction d'origine est %d\n", isalpha(ch));
// 	return (0);
// }
