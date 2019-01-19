/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:21:57 by pasankosi         #+#    #+#             */
/*   Updated: 2018/10/28 17:04:34 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../../libft/includes/libft.h"
# define CLEAR_TERM " \e[1;1H\e[2J"
# define BUFF_SIZE 10000
# define SHELL "../inc/shell.h"
# define GUIDE "[FEILD] [VALUE]\n"
# define GUIDE1 "[FEILD]\n"
# define FREE(x) ft_memdel((void *)&x)
# define R_ISNULL(x, n) if (x[n] == NULL) return (x)

char			**g_env;
/*
**env
*/
char			**dup_array(char **src);
void			update_shlvl();
typedef struct	s_inp
{
	int			started;
	int			executed;
	char		*cmd;
	char		*line;
	char		**par;
	char		buf[BUFF_SIZE + 1];
	pid_t		pid;
}				t_inp;
void			update_shlvl();
void			unsetenv_builtin(t_inp *in);
/*
** setenv_builtin.c
*/
void			setenv_builtin(t_inp *in);
char			*get_substr(char *str, char *tmp);
int				get_index(char **env, char *tmp1);
char			**add_elem_array(char **env, char *elem);
void			start_set(t_inp *in);
int				is_env(char **env, char *tmp1);
/*
** update_shlvl.c
*/
char			*get_substr(char *str, char *tmp);
void			update_shlvl();
/*
** echo_builtin.c
*/
void			echo_buitin(t_inp *in);
/*
** env_builtin.c
*/
int				env_builtin(t_inp *in);
/*
**  exec.c
*/
int				exec(t_inp *in);
int				exec_bin(t_inp *in);
int				ex_builtins(t_inp *in);
/*
** garbage_handler.c
*/
void			tidy_up(t_inp *in);
void			clean_array(char ***str);
void			arr_del(char **arr);
/*
** prompt_handler.c
*/
void			prompt_handler(char **en, t_inp in);
void			do_prompt();
void			out();
/*
** main.c
*/
void			initenv(char **en, t_inp *in);
/*
**read_handler.c
*/
void			start_reading(t_inp *in);
/*
**argument_handler.c
*/
void			argument_handler(t_inp *in);
static void		grab_pars(t_inp *in);
static void		grab_command(t_inp *in);
int				len(char *str);
/*
**cd_builtin.c
*/
void			cd_builtin(t_inp *in);
/*
**is_bin
*/
void			is_bin(t_inp *in, char **paths);
char			**get_prog_path();
int				is_executable(struct stat f, t_inp *in);
/*
**token
*/
char			**tokenize(char const *s);
#endif
