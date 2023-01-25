/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:32:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/25 09:20:30 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_stack	*tmp;

	if (!ft_start_data(ac, av, &data))
		return (0);
	if (!ft_verifynotsame(&data))
		return (0);
	ft_algo(&data);
	while (data.stack_a)
	{
		tmp = data.stack_a;
		data.stack_a = data.stack_a->next;
		free(tmp);
	}
}
