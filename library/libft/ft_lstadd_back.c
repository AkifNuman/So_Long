/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:00:30 by bkas              #+#    #+#             */
/*   Updated: 2023/07/13 17:41:53 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*swap;

	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			swap = ft_lstlast(*lst);
			swap->next = new;
		}
	}
}
