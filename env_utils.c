/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:14:47 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/07/10 16:03:15 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/* void	func_2_free_all_env(void)
{
	free_delete_add(NULL, FREE);
} */

void	free_all_env(t_env **env)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *env;
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		free(tmp->name);
		free(tmp);
	}
}

void	particular_env_free(t_env01 *env)
{
	free(env->str);
	free(env);
}
