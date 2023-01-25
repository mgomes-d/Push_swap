/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:28:23 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/20 09:31:07 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_navigatelist(t_stack *lst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_isdigitsymbol(char c)
{
	if (ft_isdigit(c) || ft_issymbol(c))
		return (1);
	else
		return (0);
}

static int	ft_errorint(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	return (0);
}

int	ft_verifynotsame(t_data *data)
{
	t_stack	*first;
	t_stack	*second;

	first = data->stack_a;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (first->content == second->content)
				return (ft_errorint(data->stack_a));
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}

int	ft_done(t_data *data)
{
	t_stack	*temp;

	if (data->stack_b)
		return (0);
	temp = data->stack_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
