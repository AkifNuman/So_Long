/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:53:12 by bkas              #+#    #+#             */
/*   Updated: 2023/07/15 13:44:33 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pntr;

	pntr = malloc(size * count);
	if (!(pntr))
		return (NULL);
	ft_bzero(pntr, (count * size));
	return (pntr);
}
