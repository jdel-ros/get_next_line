/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gnlmain.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lelegros <lelegros@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 15:16:51 by lelegros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 10:59:05 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int        main(int ac, char **av)
{
    int        fd;
    int        i;
    char    *line;
    int        j;
    int        ret;

    line = 0;
    ret = 0;
    ac = (int)ac;
    av = (char**)av;
    j = 0;
    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else
        fd = 1;

    while ((ret = get_next_line(fd, &line)))
    {
        i = 0;
        if (ret == -1)
        {
            free(line);
            return (0);
        }
        while (line[i])
        {
            write(1, &line[i], 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
        free(line);
    }
    i = 0;
if (line && line[i])
    {
        while (line[i])
        {
            write(1, &line[i], 1);
            i++;
        }
        write(1, "\n", 1);
        free(line);
    }
else
    free(line);
    dprintf(1, "LIGNES LUES = %d\n", j);
    return (0);
}
