/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raditz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:47:53 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/20 09:30:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_raditz(t_data *data)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	size = ft_lstsizestack(data->stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = data->stack_a->content;
			if (((num >> i) & 1) == 1)
				ft_ra(data, 0);
			else
				ft_pb(data);
		}
		while (data->stack_b)
			ft_pa(data);
	}
}

void	ft_4numbers(t_data *data, t_stack *stack)
{
	t_stack	*temp;
	t_stack	*smallest;
	int		size;
	int		pivot;

	smallest = stack;
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
	ft_3numbers(data, data->stack_a);
	ft_pa(data);
}
