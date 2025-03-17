/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:37:12 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/11 12:49:44 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freestruct(t_data *data)
{
	int	i;

	if (data->hd == 1)
		free(data->hd_word);
	i = 0;
	if (data->files != NULL)
	{
		while (data->files[i] != NULL)
			free(data->files[i++]);
		free(data->files);
	}
	if (data->cmd != NULL)
	{
		i = 0;
		while (data->cmd[i] != NULL)
			free(data->cmd[i++]);
		free(data->cmd);
	}
	if (data->envp != NULL)
	{
		i = 0;
		while (data->envp != NULL && data->envp[i] != NULL)
			free(data->envp[i++]);
		free(data->envp);
	}
}
