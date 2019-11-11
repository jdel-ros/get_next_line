/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 14:48:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 18:35:15 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int		checkstock(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	i--;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

int		get_next_line_2(int fd, char **line)
{
	int ret;
	static char buf[BUFFER_SIZE + 1];
	int i;
	int j;
	char *stock;

	i = 0;
	j = 0;
	stock = ft_calloc(1, 1);
	if (fd == -1)
		return (-1);
	line = (char **)malloc(sizeof(char *) * 2);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		printf("len = %d\n", ft_strlenbn(buf));
		if (ft_strlenbn(buf) < BUFFER_SIZE && stock[0] == '\0')
		{
			line[i] = ft_strdupbn(buf);
			printf("OUI  =  %s\n", line[i]);
			return (1);
		}
		else
		{
			while (j != BUFFER_SIZE + 1)
			{
				if (buf[j] == '\0')
				{
					printf("BUF = %s\n", buf);
					stock = ft_strjoin(stock, buf);
					printf("STOCK = %s\n", stock);
				}
				if (buf[j] == '\n')
				{
					printf("BUF = %s\n", buf);
					stock = ft_strjoin(stock, buf);
					line[i] = ft_strdup(stock);
					j = BUFFER_SIZE;
					printf("LINE = %s\n", line[i]);
					free(stock);
					stock = ft_calloc(1, 1);
					printf("STOCK FREE = %s\n", stock);
					i++;
				}
				j++;
			}
			j = 0;
		}
	}
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
		ret = get_next_line_2(fd, &buf[i]);
		close (fd);
	}
	printf("%d\n", ret);
}
