/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:26:58 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/03/10 17:15:51 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.argc = argc - 1;
	data.hd = 0;
	if (parsing(argv++, envp, &data) == 0)
		return (0);
	return (0);
}
