/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:48:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/25 09:18:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3numbers(t_data *data, t_stack *stack)
{
	t_stack	*first;
	t_stack	*sec;
	t_stack	*th;

	first = stack;
	sec = first->next;
	th = sec->next;
	if (sec->content < first->content && first->content < th->content)
		ft_sa(data, 0);
	else if (first->content > sec->content && sec->content > th->content)
	{
		ft_sa(data, 0);
		ft_rra(data, 0);
	}
	else if (first->content > th->content && sec->content < th->content)
		ft_ra(data, 0);
	else if (first->content < th->content && sec->content > th->content)
	{
		ft_sa(data, 0);
		ft_ra(data, 0);
	}
	else if (th->content < first->content && sec->content > first->content)
		ft_rra(data, 0);
}

t_stack	*ft_smallest(int *size, t_stack *temp)
{
	t_stack	*smallest;
	t_stack	*temp2;

	smallest = temp;
	temp2 = temp;
	while (temp)
	{
		if (temp->content < smallest->content)
			smallest = temp;
		temp = temp->next;
	}
	while (temp2)
	{
		if (temp2->content == smallest->content)
			break ;
		(*size)++;
		temp2 = temp2->next;
	}
	return (smallest);
}

static void	ft_5numbers(t_data *data)
{
	t_stack	*smallest;
	t_stack	*temp;
	int		i;
	int		size;
	int		pivot;

	i = -1;
	while (++i < 2)
	{
		size = 0;
		temp = data->stack_a;
		smallest = ft_smallest(&size, temp);
		pivot = ft_lstsizestack(data->stack_a) / 2;
		while (data->stack_a->content > smallest->content)
		{
			if (size < pivot)
				ft_ra(data, 0);
			else
				ft_rra(data, 0);
		}
		ft_pb(data);
	}
	ft_3numbers(data, data->stack_a);
	ft_pa(data);
	ft_pa(data);
}

static void	ft_2numbers(t_data *data)
{
	if (data->stack_a->content > data->stack_a->next->content)
		ft_ra(data, 0);
	return ;
}

void	ft_algo(t_data *data)
{
	int	size;

	size = ft_lstsizestack(data->stack_a);
	if (ft_done(data))
		return ;
	if (size <= 1)
		return ;
	else if (size == 2)
		ft_2numbers(data);
	else if (size == 3)
		ft_3numbers(data, data->stack_a);
	else if (size == 4)
		ft_4numbers(data, data->stack_a);
	else if (size == 5)
		ft_5numbers(data);
	else
	{
		ft_sort_struct(data);
		ft_raditz(data);
	}
}
