/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:54:00 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/16 12:02:56 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!data)
		return ;
	first = data->stack_a;
	if (!first)
		return ;
	second = first->next;
	data->stack_a = second;
	last = ft_lstlaststack(data->stack_a);
	last->next = first;
	first->next = NULL;
	if (!i)
		ft_printf("ra\n");
}

void	ft_rb(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!data)
		return ;
	first = data->stack_b;
	if (!first)
		return ;
	second = first->next;
	data->stack_b = second;
	last = ft_lstlaststack(data->stack_b);
	last->next = first;
	first->next = NULL;
	if (!i)
		ft_printf("rb\n");
}

void	ft_rr(t_data *data)
{
	ft_ra(data, 1);
	ft_rb(data, 1);
	ft_printf("rr\n");
}
