/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:54:00 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/26 00:05:52 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (buffer == 0)
		return (NULL);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (buffer);
}

// int	main(void)
// {
// 	char	src[] = "dolor sit amet";
// 	char	dest[] = "lorem ipsum";
// 	printf("le resultat de cat est '%s'\n", ft_strjoin(dest, src));
// 	return (0);
// }
