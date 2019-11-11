/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testread.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 10:29:04 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:06:26 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_2.h"

char		*read_line(char *str, int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int				i;
	static char		*str;

	str = read_line(str, fd);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (i == 0)
		*line = ft_strdup("", 1);
	else
		*line = ft_strdup(str, i);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int ret;
	int fd;
	char *buf[BUFFER_SIZE + 1];

	ret = 0;
	i = 1;
	if (argc > 1)
	{
		fd = open(argv[i], O_RDONLY);
		ret = get_next_line(fd, &buf[i]);
		close (fd);
	}
	printf("%d\n", ret);
}
