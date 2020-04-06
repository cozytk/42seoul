/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 04:24:37 by taekkim           #+#    #+#             */
/*   Updated: 2020/04/05 04:24:44 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	tri;
	int	lit_len;

	if (*little == 0)
		return ((char *)big);
	lit_len = ft_strlen(little);
	while (len--)
	{
		tri = 0;
		while (*big++ == *little++ && len >= (size_t)lit_len)
		{
			tri++;
			if (tri == lit_len)
				return ((char *)(big - tri));
		}
		big -= tri;
		little -= tri + 1;
	}
	return (0);
}
