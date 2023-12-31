/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:50 by cpopolan          #+#    #+#             */
/*   Updated: 2023/08/21 17:31:35 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_split
{
	int		i;
	int		y;
	int		x;
	int		check;
	char	**tab;
}		t_split;

typedef enum type
{
	NON,			
	ARG,			
	BUILTIN,		
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREAT_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS
}	t_e_type;

typedef struct s_token
{
	char				*token;
	int					pos;
	t_e_type			type;
	struct s_token		*next;
}		t_token;

typedef struct s_env01
{
	char			*str;
	int				declare;
	struct s_env01	*next;
}				t_env01;

typedef struct s_expander {
	char	*value;
	int		check;
	int		i;
	int		n;
	int		new_len;
	int		initial;
	char	*searchname;
	char	*new_str;
}	t_expander;

typedef struct s_command_line
{
	char					*new_matrix_string;
	t_token					*single_token;
	t_env01					*env_list;
	char					**argv;
	int						fd_in;
	int						fd_out;
	char					*name_file;
	char					*heredoc_delimiter;
	char					*input;
	pid_t					*pid;
	struct s_command_line	*next;
}	t_command_line;

int				ft_strcmp(char *str1, char *str2);
int				ft_easy_split_rows_counter(char *input);
t_env01			*ft_env_noder(char **envp);
void			ft_env_deleter(t_env01 *first);
int				ft_check_quote(char c, int check);
void			ft_lexer(char *input, t_env01 **env_list);
t_token			*ft_newnode(char *token, int pos);
t_token			*ft_initialize(t_command_line *first, t_env01 *env_list);
void			ft_final_stamper(t_command_line *cmd_line);
void			ft_node_deleter(t_token *first);
char			*get_current_dir_name(void);
t_command_line	*ft_new_matrix(char **matrix);
t_e_type		ft_node_builtin_typer(char	*token);
t_e_type		ft_node_redirect_typer(char *token);
char			*expander(char*str, t_env01 *env_list);
t_env01			*ft_env_search(t_env01 *env_list, char *searchname);
void			ft_built_in_env(char **args, t_env01 *my_env);
char			*ft_value_extractor(t_env01 *env_list);
int				ft_env_list_equal_position(t_env01 *env_list);
char			*ft_value_extractor(t_env01 *env_list);
char			**easy_split(char *str);
int				ft_easy_split_rows_counter(char *input);
char			**quote_cleaner_split(char *str, t_env01 *env_list);
void			ft_easy_split_continue03(t_split *pippo, char *str);
int				ft_symbol_checker(char *input);
int				ft_only_spaces_checker(char *input);
int				ft_symbol_quote_checker(char *input, int i);
int				ft_symbol_double_check_maj(char *input, int *i);
int				ft_symbol_double_check_min(char *input, int *i);
int				ft_saltaspazi(char *input, int i);
void			ft_majia(char **matrix);
int				ft_check_maj_error(void);
int				ft_check_min_error(void);
char			*ft_itoa_original(int n);

//expander_UTILS
void			ft_exit_expander(t_expander **exp);
int				ft_dollar_checker(char *str, t_expander *exp);
char			*ft_value_extractor(t_env01 *env_list);
int				ft_env_list_equal_position(t_env01 *env_list);
t_env01			*ft_env_search(t_env01 *env_list, char *searchname);

#endif
