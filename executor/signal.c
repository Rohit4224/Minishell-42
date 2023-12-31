/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:35 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/08/18 11:15:16 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

extern int	g_exit_status;

/* the function sets g_exit_status to 130. 
This value is commonly used to indicate that
the program was terminated by a SIGINT*/

void	ft_signal_cmd(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_cmd_2(int sig)
{
	g_exit_status += sig;
	if (sig == 2)
	{
		g_exit_status = 130;
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
