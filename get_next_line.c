/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:14:31 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 15:56:15 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char		*read_line(char *str, int fd)
{
	int			ret;
	int			i;
	char		buf[BUFFER_SIZE + 1];

	ret = 1;
	while (ret != 0)
	{
		i = 0;
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				ret = 0;
			i++;
		}
		str = ft_strjoin(str, buf);
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int				i;
	static char		*str;

	i = 0;
	if (fd == -1)
		return (-1);
	*line = ft_strdupnul();
	if (str != NULL)
		str = ft_strrchr(str, '\n');
	if (str == NULL)
		str = ft_strdupnul();
	str = read_line(str, fd);
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			free(str);
			return (0);
		}
		i++;
	}
	free(*line);
	*line = ft_strdup(str);
	return (1);
}
