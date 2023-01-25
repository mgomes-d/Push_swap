/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:32:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/25 08:20:29 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_start_data(ac, av, &data))
		return (0);
	if (!ft_verifynotsame(&data))
		return (0);
	ft_algo(&data);
	system("leaks push_swap");
}
