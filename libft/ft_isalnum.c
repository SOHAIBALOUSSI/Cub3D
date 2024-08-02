/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-gha <moel-gha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:59:53 by moel-gha          #+#    #+#             */
/*   Updated: 2023/11/06 15:49:26 by moel-gha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int al_num)
{
	if ((al_num >= 97 && al_num <= 122) || (al_num >= 65 && al_num <= 90)
		|| (al_num >= 48 && al_num <= 57))
		return (1);
	return (0);
}
