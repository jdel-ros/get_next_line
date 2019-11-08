/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   testread.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 10:29:04 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 17:24:32 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int ret;
	static char buf[BUFFER_SIZE + 1];
	int i;
	int count;

	i = 0;
	count = 0;
	if (fd == -1)
		return(-1);
	printf("fd = %d\n", fd);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		printf("ret = %d et ", ret);
		printf("buf = %s\n", buf);
		line[i] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		line[i] = ft_strdup(buf);
		i++;
	}
	i = 0;
	while (line[i])
	{
		printf("%s", line[i]);
		i++;
	}
	while (i != 0)
	{
		free(line[i]);
		i--;
	}
	free (line[i]);
	return (ret);
}

int		main(int argc, char **argv)
{
	int i;
	int ret;
	int fd;
	char *buf[BUFFER_SIZE + 1];

	i = 1;
	if (argc > 1)
	{
		fd = open(argv[i], O_RDONLY);
		ret = get_next_line(fd, &buf[i]);
		close (fd);
	}
}
