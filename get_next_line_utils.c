/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utlis.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:07:37 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 16:08:01 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_strlenbn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
void			ft_bzero(void *s, size_t n)
{
	size_t i;
	char *str					;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	s = str;
}

char		*ft_strdupbn(char *s)
{
	int i;
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlenbn(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char		*ft_strdup(char *s)
{
	int i;
	char *dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


char		*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '\n')
			i++;
		str[j++] = s1[i++];
	}
	free(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		if (s2[i] == '\n')
			i++;
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

void			*ft_calloc(size_t nmemb, size_t size)
{
	void*str;

	if (!(str = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(str, (nmemb * size));
	return (str);
}
