/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:55:28 by bkas              #+#    #+#             */
/*   Updated: 2023/07/07 15:28:30 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *)s1)[c] != ((unsigned char *)s2)[c])
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
		c++;
	}
	return (0);
}
