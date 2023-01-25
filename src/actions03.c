/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:54:15 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/16 12:05:52 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*beforelast;
	t_stack	*last;
	int		size;

	if (!data)
		return ;
	first = data->stack_a;
	last = ft_lstlaststack(data->stack_a);
	size = ft_lstsizestack(data->stack_a);
	beforelast = ft_navigatelist(data->stack_a, size - 2);
	if (!last || !size || !first)
		return ;
	data->stack_a = last;
	last->next = first;
	beforelast->next = NULL;
	if (!i)
		ft_printf("rra\n");
}

void	ft_rrb(t_data *data, int i)
{
	t_stack	*first;
	t_stack	*beforelast;
	t_stack	*last;
	int		size;

	if (!data)
		return ;
	first = data->stack_b;
	last = ft_lstlaststack(data->stack_b);
	size = ft_lstsizestack(data->stack_b);
	beforelast = ft_navigatelist(data->stack_b, size - 2);
	if (!last || !size || !first)
		return ;
	data->stack_b = last;
	last->next = first;
	beforelast->next = NULL;
	if (!i)
		ft_printf("rrb\n");
}

void	ft_rrr(t_data *data)
{
	ft_rra(data, 1);
	ft_rrb(data, 1);
	ft_printf("rrr\n");
}
