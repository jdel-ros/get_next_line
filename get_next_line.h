/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:08:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 17:57:22 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_2_H
# define GET_NEXT_LINE_2_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);
char		*ft_strrchr(char *s, char c);
#endif
