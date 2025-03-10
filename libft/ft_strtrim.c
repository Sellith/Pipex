/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:08:29 by lvan-bre          #+#    #+#             */
/*   Updated: 2024/10/27 00:33:48 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*buffer;
	size_t	trimmed;

	while (ft_strchr(set, *s1) && *s1)
		s1++;
	trimmed = ft_strlen(s1);
	while (ft_strchr(set, s1[trimmed - 1]) && trimmed > 0)
		trimmed--;
	buffer = malloc(trimmed + 1);
	if (buffer == NULL)
		return (NULL);
	ft_strlcpy(buffer, s1, trimmed + 1);
	return (buffer);
}
