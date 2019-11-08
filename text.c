/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   text.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdel-ros <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 11:49:04 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 16:01:40 by jdel-ros    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		ft_text(char *s1)
{
	int i;

	i = strlen(s1);
	printf("%d\n", i);
	return (i);
}

int		main()
{
	char s1[] = "1What's up dude!";
	ft_text(s1);
	return (0);
}
