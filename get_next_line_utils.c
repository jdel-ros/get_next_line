/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utlis.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:07:37 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 15:38:53 by jdel-ros    ###    #+. /#+    ###.fr     */
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

char		*ft_strdup(const char *s)
{
	int i;
	char *dup;

	i = 0;
	while (s[i])
		i++;
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int i;
	int j;

	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + ft_strlen((char *)s2)))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
		i = 0;
		while (s2[i])
		{
			str[j++] = s2[i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
