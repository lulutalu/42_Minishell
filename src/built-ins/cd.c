//
// Created by Lowell Zima on 5/30/22.
//

#include "./../../includes/minishell.h"

static char	*get_home_path(char *path)
{
	char *tmp;
	char *tmpp;

	if(ft_strncmp(path, "~/", 2))
	{
		if((tmp = getenv("HOME")))
		{
			tmpp = ft_substr(path, 1, ft_strlen(path));
			free(path);
			path = ft_strjoin(tmp, tmpp);
			free(tmpp);
			free(tmp);
			return (path);
		}
	}
	return (path);
}

static int change(char *path, int home)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			set_env("OLDPWD, pwd")
		}
	}
}

