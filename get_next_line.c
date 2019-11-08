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
	int j;
	int countline;
	char *stock;

	countline = 1;
	i = 0;
	j = 0;
	stock = ft_calloc(1, 1);
	if (fd == -1)
		return(-1);
	printf("fd = %d\n", fd);
	line = (char **)malloc(sizeof(char*) * (1));
	printf("BUFFER_SIZE = %d\n ", BUFFER_SIZE);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		while (j != BUFFER_SIZE + 1)
		{
			if (buf[j] == '\0')
			{
				printf("[IN1]\n");
				printf("BUF = %s\n", buf);
				stock = ft_strjoin(stock, buf);
				printf("STOCK = %s\n", stock);
				printf("[OUT1]\n");
			}
			if (buf[j] == '\n')
			{
				printf("[IN2]\n");
				line[i] = ft_strdup(stock);
//				line[i] = stock;
//				line[i][ft_strlen(line[i])] = '\0';
				printf("LINE%d = %s\n", countline, line[i]);
				countline++;
				stock = ft_calloc(1, 1);
				i++;
				printf("[OUT2]\n");
			}
			j++;
		}
		j = 0;
	}
/*	while (i != 0)
	{
		free(line[i]);
		i--;
	}
	free (line[i]);
	return (ret);*/
	return (0);
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
