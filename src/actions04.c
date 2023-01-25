/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions04.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:54:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/17 10:43:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_data *data)
{
	t_stack	*second;
	t_stack	*first;

	first = data->stack_b;
	if (!first)
		return ;
	second = first->next;
	data->stack_b = second;
	ft_lstadd_frontstack(&data->stack_a, first);
	ft_printf("pa\n");
}

void	ft_pb(t_data *data)
{
	t_stack	*second;
	t_stack	*first;

	first = data->stack_a;
	if (!first)
		return ;
	second = first->next;
	data->stack_a = second;
	ft_lstadd_frontstack(&data->stack_b, first);
	ft_printf("pb\n");
}
