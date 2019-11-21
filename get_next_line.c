/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:14:31 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 16:16:44 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static int				strlenbn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int				checkstr(char **str, char **line)
{
	while (*str != NULL)
	{
		if (strlenbn(*str) == 1)
		{
			*line = ft_strdup(*str);
			*str = ft_strchrcut(*str, '\n');
			return (1);
		}
		else if (strlenbn(*str) == 0)
		{
			*line = *str;
			*str = NULL;
			return (1);
		}
	}
	if (*str == NULL)
	{
		*line = "";
		return (0);
	}
	return (0);
}

static int				ifbnok(char **str, char **line)
{
	if (strlenbn(*str) == 1)
	{
		if ((*line = ft_strdup(*str)) == NULL)
			return (-1);
		*str = ft_strchrcut(*str, '\n');
		return (1);
	}
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static char		*str;
	int				ret;
	int				ret1;
	char			buf[BUFFER_SIZE + 1];

	ret = 1;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (str == NULL)
			if ((str = ft_strdupclas("")) == NULL)
				return (-1);
		buf[ret] = '\0';
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (-1);
		ret1 = ifbnok(&str, line);
		if (ret1 != 0)
			return (ret1);
	}
	if ((ret1 = checkstr(&str, line)) == 0)
		return (0);
	else
		return (1);
}
