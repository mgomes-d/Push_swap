/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:53:50 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/17 12:26:56 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	first = data->stack_a;
	second = first->next;
	third = second->next;
	data->stack_a = second;
	second->next = first;
	first->next = third;
	if (!i)
		ft_printf("sa\n");
}

void	ft_sb(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	first = data->stack_b;
	second = first->next;
	third = second->next;
	data->stack_b = second;
	second->next = first;
	first->next = third;
	if (!i)
		ft_printf("sb\n");
}

void	ft_ss(t_data *data)
{
	ft_sa(data, 1);
	ft_sb(data, 1);
	ft_printf("ss\n");
}
