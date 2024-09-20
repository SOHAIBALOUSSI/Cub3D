/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:22:18 by moel-gha          #+#    #+#             */
/*   Updated: 2023/11/22 16:22:23 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../src/cub3D.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)m_alloc(sizeof(t_list), ALLOC);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
