/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 03:19:28 by taekkim           #+#    #+#             */
/*   Updated: 2020/04/13 19:24:42 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **mat, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int		ft_row(const char *str, char c)
{
	int row;
	int i;

	i = 0;
	row = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			row++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (row);
}

int		ft_vec(const char *str, char c)
{
	static int	i;
	int			vec;

	vec = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		vec++;
		i++;
	}
	return (vec);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	if (ft_row(s, c) == 0)
	{
		printf("HI\n");
		return (0);
	}
	if (!(dest = (char **)malloc(sizeof(char *) * (ft_row(s, c) + 1))))
		return (0);
	i = 0;
	k = 0;
	while (s[k] && (i < ft_row(s, c)))
	{
		j = 0;
		if (!(dest[i] = (char *)malloc(sizeof(char) * (ft_vec(s, c) + 1))))
		{
			ft_free(dest, i);
			return (0);
		}
		while (s[k] && (s[k] == c))
			k++;
		while (s[k] && (s[k] != c))
			dest[i][j++] = s[k++];
		dest[i++][j] = 0;
	}
	dest[i] = 0;
	return (dest);
}
