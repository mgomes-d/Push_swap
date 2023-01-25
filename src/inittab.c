/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inittab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:43:08 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/19 11:23:35 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	temp;

	if (!size || !tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		min = i;
		while (j < size)
		{
			if (tab[min] > tab[j])
				min = j;
			j++;
		}
		temp = tab[i];
		tab[i] = tab[min];
		tab[min] = temp;
		i++;
	}
	return (tab);
}

static int	*ft_parsing(t_data *data)
{
	int		*tab;
	int		i;
	t_stack	*temp;

	tab = malloc(sizeof(int) * ft_lstsizestack(data->stack_a) + 1);
	if (!tab)
		return (NULL);
	temp = data->stack_a;
	if (!temp)
		return (0);
	i = 0;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	tab = ft_sort_tab(tab, i);
	return (tab);
}

static void	ft_put_tabinstruct(int *tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->content = tab[i];
		stack = stack->next;
		i++;
	}
	free(tab);
}

static int	*ft_parsingtab(t_data *data)
{
	int		*tab;
	int		i;
	t_stack	*temp;

	tab = malloc(sizeof(int) * ft_lstsizestack(data->stack_a) + 1);
	if (!tab)
		return (NULL);
	temp = data->stack_a;
	if (!temp)
		return (0);
	i = 0;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (tab);
}

void	ft_sort_struct(t_data *data)
{
	int	*tab;
	int	i;
	int	j;
	int	size;
	int	*finaltab;

	finaltab = ft_parsingtab(data);
	tab = ft_parsing(data);
	i = 0;
	size = ft_lstsizestack(data->stack_a);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (finaltab[i] == tab[j])
				finaltab[i] = j;
			j++;
		}
		i++;
	}
	i = 0;
	free(tab);
	ft_put_tabinstruct(finaltab, data->stack_a);
}
