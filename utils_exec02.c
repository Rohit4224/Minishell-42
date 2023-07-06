/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:51:23 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/07/06 16:29:14 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	all_free_n_exit(t_command_line **cmd,
	pid_t *pid, char **str)
{
	free_all(cmd);
	func_2_free_all_env();
	free(pid);
	free(str);
	exit(1);
}
