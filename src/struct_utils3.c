/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 08:34:23 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/20 09:31:15 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_int_str_utils(char *str, int j, t_stack **listall)
{
	int		k;
	char	*temp;
	int		error;

	k = 0;
	error = 0;
	if (ft_issymbolnumberstr(str))
	{
		while (str[j + k] && ft_isdigitsymbol(str[j + k]))
			k++;
		temp = ft_substr(str, j, k);
		ft_lstadd_backstack(listall, ft_lstnewstack(ft_atoi(temp, &error)));
		free(temp);
	}
	if (error == 1)
		return (-1);
	return (k);
}
