/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utlis.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:07:37 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 15:30:18 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;
	int			len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	free(s1);
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

char			*ft_strdupclas(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char			*ft_strdup(char *str)
{
	int		j;
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
				return (NULL);
			j = 0;
			while (j < i)
			{
				dup[j] = str[j];
				j++;
			}
			dup[j] = '\0';
			return (dup);
		}
		i++;
	}
	return (ft_strdupclas(str));
}

char			*ft_strchrcut(char *s, char c)
{
	int			i;
	char		*res;

	res = ft_strdupclas("");
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res = ft_strjoin(res, s + (i + 1));
			free(s);
			return (res);
		}
		i++;
	}
	return (0);
}
