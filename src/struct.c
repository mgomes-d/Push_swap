/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:24:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/20 09:31:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_error(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	write(2, "Error\n", 6);
	return (NULL);
}

static int	ft_have_symbol_or_number(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_issymbolnumberstr(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static t_stack	*ft_put_in_struct(char **av)
{
	t_stack	*listall;
	int		i;
	int		error;

	i = 1;
	listall = NULL;
	error = 0;
	if (!ft_have_symbol_or_number(av))
		return (ft_error(listall));
	while (av[i])
	{
		if (ft_issymbolnumberstr(av[i]))
			ft_lstadd_backstack(&listall, \
			ft_lstnewstack(ft_atoi(av[i++], &error)));
		else
			return (ft_error(listall));
		if (error == 1)
			return (ft_error(listall));
	}
	return (listall);
}

static t_stack	*ft_put_in_struct_str(char **av)
{
	t_stack	*listall;
	int		j;
	int		k;

	j = 0;
	listall = NULL;
	while (av[1][j])
	{
		k = ft_put_int_str_utils(av[1], j, &listall);
		if (k == -1)
			return (ft_error(listall));
		j += k;
		while (av[1][j] && av[1][j] == ' ')
			j++;
		if ((av[1][j] != ' ' && !ft_issymbolnumberstr(av[1]) && av[1][j]))
			return (ft_error(listall));
	}
	return (listall);
}

int	ft_start_data(int ac, char **av, t_data *data)
{
	if (ac == 1)
		return (0);
	if (!av[1])
		return (0);
	else if (ac == 2)
		data->stack_a = ft_put_in_struct_str(av);
	else
		data->stack_a = ft_put_in_struct(av);
	if (!data->stack_a)
		return (0);
	data->stack_b = NULL;
	return (1);
}
