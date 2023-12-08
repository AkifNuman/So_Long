/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:40:08 by bkas              #+#    #+#             */
/*   Updated: 2023/07/13 16:41:50 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sc;
	size_t	i;

	dest = (char *)dst;
	sc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dest[i] = sc[i];
		i++;
	}
	return (dst);
}
